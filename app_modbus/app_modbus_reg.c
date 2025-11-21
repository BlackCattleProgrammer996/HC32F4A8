#include "MBx_api.h"
#include "app_uart.h"
#include "main.h"
#include "app_modbus_reg.h"
#include <stdint.h>
#include <stdio.h>

//数据来源头文件
#include "Measure.h"
#include "Measure_Other.h"
#include "User.h"
#include "Log.h"
#include "System.h"
#include "Data_Write.h"
#include "Protect.h"

static uint8_t DisplaySetMode = SET_MODE_DISPLAY;


uint32_t appMBX_Write_2000(void *value)
{
	if(DEF_Normal == dWrite_Protect_I_Ir(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2001(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tr(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2002(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_CoolingTime(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2003(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Curve(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2004(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Isd(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2005(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tsd(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2006(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_IsdType(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2007(void *value)
{
	if(DEF_Normal == dWrite_Protect_I_Ii(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2008(void *value)
{
	if(DEF_Normal == dWrite_Protect_I_IiPeakSwitch(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2009(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Ig(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200A(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_IgType(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200B(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tg(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200C(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Ie(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200D(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Te(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200E(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Iw(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_200F(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_IwType(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2010(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tw(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2011(void *value)
{
	if(DEF_Normal == dWrite_OtherProtect_IgAlarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2012(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IgAlarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2013(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IgAlarm_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2014(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IgAlarm_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2015(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IeAlarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2016(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IeAlarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2017(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IeAlarm_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2018(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IeAlarm_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2019(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IwAlarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IwAlarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IwAlarm_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IwAlarm_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_IrPreAlarm(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Ir_Alarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_201F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Ir_Alarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2020(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Isd_Alarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2021(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Isd_Alarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2022(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Ii_Alarm_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2023(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Ii_Alarm_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2050(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Ir2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2051(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tr2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2052(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Isd2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2053(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tsd2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2054(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Ii2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2055(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_IiPeakSwitch2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2056(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Ig2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2057(void *value)
{
    if(DEF_Normal == dWrite_Protect_I_Tg2(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2100(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_Unbalance_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2101(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_Unbalance_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2102(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_Unbalance_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2103(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_Unbalance_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2104(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_OpenPhase_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2105(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_OpenPhase_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2106(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_OpenPhase_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2107(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_OpenPhase_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2108(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_LoadMonitor_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2109(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_LoadMonitor_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_LoadMonitor_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_I_LoadMonitor_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ia_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ia_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ia_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_210F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ia_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2110(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ib_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2111(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ib_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2112(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ib_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2113(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ib_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2114(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ic_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2115(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ic_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2116(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ic_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2117(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Ic_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2118(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Id_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2119(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Id_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Id_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_Id_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_211F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2120(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2121(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2122(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2123(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2124(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2125(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2126(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2127(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_Unbalance_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2128(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_OpenPhase_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2129(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_OpenPhase_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_U_OpenPhase_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212B(void *value)
{
	if(DEF_Normal == dWrite_OtherProtect_U_OpenPhase_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderFrequency_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderFrequency_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderFrequency_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_212F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderFrequency_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2130(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverFrequency_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2131(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverFrequency_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2132(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverFrequency_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2133(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverFrequency_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2134(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_FrequencyChangeRate_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2135(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_FrequencyChangeRate_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2136(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_FrequencyChangeRate_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2137(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_FrequencyChangeRate_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2138(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_P_LoadMonitor_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2139(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_P_LoadMonitor_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_P_LoadMonitor_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_P_LoadMonitor_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_P_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_P_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_P_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_213F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_P_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2140(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_Q_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2141(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_Q_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2142(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_Q_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2143(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Reverse_Q_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2144(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_P_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2145(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_P_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2146(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_P_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2147(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_P_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2148(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Under_P_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2149(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Under_P_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Under_P_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Under_P_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_Q_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_Q_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_Q_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_214F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Over_Q_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2150(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_P_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2151(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_P_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2152(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_P_RV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2153(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Required_P_RT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2154(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_BusBarTemperature_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2155(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_BusBarTemperature_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2156(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_BusBarTemperature_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2157(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_BusBarTemperature_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2158(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_PF_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2159(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_PF_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215A(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_PF_RV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215B(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_PF_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215C(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_I_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215D(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_I_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215E(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_I_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_215F(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_U_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2160(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_U_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2161(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_Harmonic_U_RT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2162(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_PhaseSequence(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2163(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderVoltage2_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2164(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_UnderVoltage2_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2165(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage2_SV(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2166(void *value)
{
    if(DEF_Normal == dWrite_OtherProtect_OverVoltage2_AT(value,&DisplaySetMode))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2400(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_1_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2401(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_1_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2402(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_2_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2403(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_2_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2404(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_3_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2405(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageSwell_3_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2406(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_1_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2407(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_1_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2408(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_2_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2409(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_2_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240A(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_3_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240B(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageDisp_3_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240C(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_VoltageShortInterruption_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240D(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_UnbalanceFactor_U_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240E(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_AverageVoltage_UpperLimit(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_240F(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_AverageVoltage_LowerLimt(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2410(void *value)
{
    if(DEF_Normal == dWrite_PowerQuality_UnbalanceFactor_I_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2500(void *value)
{
    if(DEF_Normal == dWrite_Reclose_VCU_SV(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2501(void *value)
{
    if(DEF_Normal == dWrite_Reclose_VCU_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}

uint32_t appMBX_Write_2502(void *value)
{
    if(DEF_Normal == dWrite_Reclose_Ir_AT(value))return MBX_API_RETURN_DEFAULT;
	else return MBX_API_RETURN_ERR_PARAM;
}


