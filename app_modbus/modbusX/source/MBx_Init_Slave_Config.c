/********************************************************************************


 **** Copyright (C), 2024, Yuanlong Xu <Yono233@outlook.com>    ****
 **** All rights reserved                                       ****

 ********************************************************************************
 * File Name     : MBx_Init_Slave_Config.c
 * Author        : yono
 * Date          : 2024-07-27
 * Version       : 1.0
********************************************************************************/
/**************************************************************************/
/*
    初始化MBX从机配置
    应当是库内调用
*/

/* Includes ------------------------------------------------------------------*/
#include <MBx_api.h>
#include <stdio.h>
/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private Constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
 * @brief 初始化MBX从机配置的各个参数
 * @param MBxSlaveConfig 指向MBX从机配置结构体的指针
 * @param ID 期望配置成的从机ID
 * @param MAP 指向地址映射表头的指针
 * @return 标准返回
 */
uint32_t MBx_Init_Slave_Config(_MBX_SLAVE_CONFIG *MBxSlaveConfig, uint8_t ID, const _MBX_MAP_LIST_ENTRY *MAP)
{
    uint32_t state   = MBX_API_RETURN_DEFAULT;
    uint16_t i       = 0; // 遍历map并审查
    uint32_t AddrNow = 0; // 当前审查的条目 mb寄存器地址

    /* 基础配置 */
    MBxSlaveConfig->SlaveID = ID;
    MBxSlaveConfig->Map     = MAP;

    /* 审查定义的映射表
       说明: 原实现以 MAP[i].Memory != NULL 作为结束条件。但映射表中可能存在 Memory==NULL
       的合法条目（例如只写回调或占位），这会导致初始化在表中间错误截断。
       正确的终止应与库中定义的 MBX_MAP_LIST_END 保持一致，该宏设置 Addr==0 且 Type==0。
       因此这里改为以 Addr==0 && Type==0 作为结束判定，从而允许 Memory==NULL 的条目存在。
    */
    for(i = 0;                                      // 从0开始遍历
        (i < 0xFFFEU) &&                            // 条件1 防止意外无限循环卡死
        !((MAP[i].Addr == 0u) && (MAP[i].Type == 0u)); // 条件2 遇到 MBX_MAP_LIST_END (Addr==0 && Type==0) 则结束
        i++)                                      // 推进
    {
        if(AddrNow > MAP[i].Addr)
        {
            state = MBX_API_RETURN_MAP_UNFORMAT;
#if defined(MBX_DEBUG) || 1
            /* 调试输出：帮助定位哪一条 MAP 条目地址不按从小到大排序 */
            printf("MBx_Init_Slave_Config MAP unformat: SlaveID=%u, idx=%u, prev=0x%04lX, curr=0x%04X\r\n",
                   (unsigned)ID, (unsigned)i, (unsigned long)AddrNow, (unsigned)MAP[i].Addr);
#endif
#if MBX_MODULE_ERR_TRACE_ENABLE
            MBxErrTraceAdd(ID, MBX_MODE_SLAVE, 0, MBX_API_RETURN_MAP_UNFORMAT);
#endif
        }
        AddrNow = MAP[i].Addr;
    }
    MBxSlaveConfig->MapNum = i; // 记录条目总数量

    return (state);
}