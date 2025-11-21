#ifndef __APP_MODBUS_H__
#define __APP_MODBUS_H__

#include "main.h"
#include "MBx_api.h"
#include "app_uart.h"

/*
 * 说明：
 * - 将设备维度与从机/主机维度分离，避免为未使用的 _MBX_SLAVE/_MBX_MASTER 分配多余空间。
 * - modbus_device_t: 表示系统中所有逻辑 Modbus 设备（用于业务层选择设备/串口）。
 * - modbus_slave_idx_t: 仅包含作为从机的设备索引（连续从 0 开始）。
 * - modbus_master_idx_t: 仅包含作为主机的设备索引（连续从 0 开始）。
 */

/* 逻辑设备总表：用于业务层标识 */
typedef enum {
    MODBUS_DEVICE_DISPLAY = 0,      // 显示屏（逻辑设备 0）
    MODBUS_DEVICE_METER,            // 计量模块（逻辑设备 1） -- 已设为 Master
    MODBUS_DEVICE_EXTERNAL_485,     // 外部485（逻辑设备 2）
    MODBUS_DEVICE_INTERNAL_485,     // 内部485（逻辑设备 3） -- 已设为 Master
    MODBUS_DEVICE_BLUETOOTH,        // 蓝牙模块（逻辑设备 4）
    MODBUS_DEVICE_TOTAL
} modbus_device_t;

/* 从机索引枚举（只包含从机）——用于索引 _MBX_SLAVE 数组与从机缓冲 */
typedef enum {
    MODBUS_SLAVE_DISPLAY = 0,       // 从机：显示屏
    MODBUS_SLAVE_EXTERNAL_485,      // 从机：外部485
    MODBUS_SLAVE_BLUETOOTH,         // 从机：蓝牙
    MODBUS_SLAVE_COUNT
} modbus_slave_idx_t;

/* 主机索引枚举（只包含主机）——用于索引 _MBX_MASTER 数组与主机缓冲 */
typedef enum {
    MODBUS_MASTER_METER = 0,        // 主机：计量模块
    MODBUS_MASTER_INTERNAL_485,     // 主机：内部485
    MODBUS_MASTER_COUNT
} modbus_master_idx_t;

/* 寄存器存储结构（业务层对每个逻辑设备保持寄存器存储） */
typedef struct {
    uint8_t coils[64];
    uint8_t discrete_inputs[64];
    uint16_t holding_registers[64];
    uint16_t input_registers[64];
} modbus_registers_t;

/* 全局对象（在 app_modbus.c 中定义） */
/* 仅为从机分配 _MBX_SLAVE 数组*/
extern _MBX_SLAVE g_modbusSlaves[MODBUS_SLAVE_COUNT];
/* 仅为主机分配 _MBX_MASTER 数组*/
extern _MBX_MASTER g_modbusMasters[MODBUS_MASTER_COUNT];
/* 业务寄存器按逻辑设备总数分配*/
//extern modbus_registers_t g_modbusRegs[MODBUS_DEVICE_TOTAL];

/* 初始化：总入口（只做寄存器清理 + 初始化主机） */
void MODBUS_Init(void);

/* 从机独立初始化函数（按需在主程序中显式调用） */
void MODBUS_Display_Slave_Init(void);
void MODBUS_External485_Slave_Init(void);
void MODBUS_Bluetooth_Slave_Init(void);

/* 主机独立初始化函数（计量模块与内部485 改为 Master） */
void MODBUS_Meter_Master_Init(void);
void MODBUS_Internal485_Master_Init(void);

/* 端口层（业务层调用，参数为逻辑设备） */
uint32_t MODBUS_SendPort(modbus_device_t device, const void *data, size_t len);
uint32_t MODBUS_ReceivePort(modbus_device_t device, uint8_t *data);

/* 单独包装（方便绑定到 modbusX） */
uint32_t MODBUS_Display_ReceivePort(uint8_t *data);
uint32_t MODBUS_Meter_ReceivePort(uint8_t *data);
uint32_t MODBUS_External485_ReceivePort(uint8_t *data);
uint32_t MODBUS_Internal485_ReceivePort(uint8_t *data);
uint32_t MODBUS_Bluetooth_ReceivePort(uint8_t *data);

uint32_t MODBUS_Display_SendPort(const void *data, size_t len);
uint32_t MODBUS_Meter_SendPort(const void *data, size_t len);
uint32_t MODBUS_External485_SendPort(const void *data, size_t len);
uint32_t MODBUS_Internal485_SendPort(const void *data, size_t len);
uint32_t MODBUS_Bluetooth_SendPort(const void *data, size_t len);

/* 高层寄存器操作接口（保持直观） */
void MODBUS_SetHoldingRegister(modbus_device_t device, uint16_t addr, uint16_t value);
uint16_t MODBUS_GetHoldingRegister(modbus_device_t device, uint16_t addr);
void MODBUS_SetInputRegister(modbus_device_t device, uint16_t addr, uint16_t value);
uint16_t MODBUS_GetInputRegister(modbus_device_t device, uint16_t addr);
void MODBUS_SetCoil(modbus_device_t device, uint16_t addr, uint8_t value);
uint8_t MODBUS_GetCoil(modbus_device_t device, uint16_t addr);


#endif
