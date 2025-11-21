# g_displayMapList Handle回调函数与Memory变量一致性检查报告

## 检查方法
对于 `g_displayMapList` 中每个有 Handle 回调函数的条目，检查：
1. Memory 字段指向的变量
2. Handle 回调函数内实际操作的变量
3. 两者是否一致

## 发现的问题

### ❌ 严重错误：PowerQuality_Set 相关函数变量不匹配

以下函数名与操作的变量不一致：

| Addr | Memory指向 | Handle函数 | 函数内操作的变量 | 状态 |
|------|-----------|-----------|----------------|------|
| 0x2400 | `&PowerQuality_Set.VoltageSwell_1_SV` | `appMBX_Write_2400` → `dWrite_PowerQuality_VoltageSwell_1_SV` | `PowerQuality_Set.VoltageDisp_1_SV` | ❌ **不匹配** |
| 0x2401 | `&PowerQuality_Set.VoltageSwell_1_AT` | `appMBX_Write_2401` → `dWrite_PowerQuality_VoltageSwell_1_AT` | `PowerQuality_Set.VoltageDisp_1_AT` | ❌ **不匹配** |
| 0x2402 | `&PowerQuality_Set.VoltageSwell_2_SV` | `appMBX_Write_2402` → `dWrite_PowerQuality_VoltageSwell_2_SV` | `PowerQuality_Set.VoltageDisp_2_SV` | ❌ **不匹配** |
| 0x2403 | `&PowerQuality_Set.VoltageSwell_2_AT` | `appMBX_Write_2403` → `dWrite_PowerQuality_VoltageSwell_2_AT` | `PowerQuality_Set.VoltageDisp_2_AT` | ❌ **不匹配** |
| 0x2404 | `&PowerQuality_Set.VoltageSwell_3_SV` | `appMBX_Write_2404` → `dWrite_PowerQuality_VoltageSwell_3_SV` | `PowerQuality_Set.VoltageDisp_3_SV` | ❌ **不匹配** |
| 0x2405 | `&PowerQuality_Set.VoltageSwell_3_AT` | `appMBX_Write_2405` → `dWrite_PowerQuality_VoltageSwell_3_AT` | `PowerQuality_Set.VoltageDisp_3_AT` | ❌ **不匹配** |

**问题描述：**
- 函数名包含 `VoltageSwell`，但函数内部操作的是 `VoltageDisp` 变量
- Memory 字段指向 `VoltageSwell_*`，但回调函数操作的是 `VoltageDisp_*`
- 这会导致写入操作写入到错误的变量

**建议修复：**
需要确认正确的变量名。如果应该操作 `VoltageSwell_*`，则修改函数实现；如果应该操作 `VoltageDisp_*`，则修改 Memory 字段。

## ✅ 已验证正确的条目（部分示例）

| Addr | Memory指向 | Handle函数 | 函数内操作的变量 | 状态 |
|------|-----------|-----------|----------------|------|
| 0x2000 | `&Protect_I_Set.Ir` | `appMBX_Write_2000` → `dWrite_Protect_I_Ir` | `Protect_I_Set.Ir` | ✅ 一致 |
| 0x2001 | `&Protect_I_Set.Tr` | `appMBX_Write_2001` → `dWrite_Protect_I_Tr` | `Protect_I_Set.Tr` | ✅ 一致 |
| 0x2002 | `&Protect_I_Set.CoolingTime` | `appMBX_Write_2002` → `dWrite_Protect_I_CoolingTime` | `Protect_I_Set.CoolingTime` | ✅ 一致 |
| 0x2003 | `&Protect_I_Set.Curve` | `appMBX_Write_2003` → `dWrite_Protect_I_Curve` | `Protect_I_Set.Curve` | ✅ 一致 |
| 0x2004 | `&Protect_I_Set.Isd` | `appMBX_Write_2004` → `dWrite_Protect_I_Isd` | `Protect_I_Set.Isd` | ✅ 一致 |
| 0x2011 | `&OtherProtect_Set.IgAlarm.SV` | `appMBX_Write_2011` → `dWrite_OtherProtect_IgAlarm_SV` | `OtherProtect_Set.IgAlarm.SV` | ✅ 一致 |
| 0x2012 | `&OtherProtect_Set.IgAlarm.AT` | `appMBX_Write_2012` → `dWrite_OtherProtect_IgAlarm_AT` | `OtherProtect_Set.IgAlarm.AT` | ✅ 一致 |
| 0x201D | `&OtherProtect_Set.IrPreAlarm` | `appMBX_Write_201D` → `dWrite_OtherProtect_IrPreAlarm` | `OtherProtect_Set.IrPreAlarm` | ✅ 一致 |
| 0x2500 | `&Reclose_Set.VCU_SV` | `appMBX_Write_2500` → `dWrite_Reclose_VCU_SV` | `Reclose_Set.VCU_SV` | ✅ 一致 |
| 0x2501 | `&Reclose_Set.VCU_AT` | `appMBX_Write_2501` → `dWrite_Reclose_VCU_AT` | `Reclose_Set.VCU_AT` | ✅ 一致 |
| 0x2502 | `&Reclose_Set.Ir_AT` | `appMBX_Write_2502` → `dWrite_Reclose_Ir_AT` | `Reclose_Set.Ir_AT` | ✅ 一致 |

## 详细问题分析

### PowerQuality_Set.VoltageSwell_* 问题详情

**问题代码位置：**
- `Parameters/Data_Write.c` 第3685-3774行

**具体问题：**

1. **函数 `dWrite_PowerQuality_VoltageSwell_1_SV` (第3685行)**
   - 函数名：`dWrite_PowerQuality_VoltageSwell_1_SV`
   - 但函数内操作：`PowerQuality_Set.VoltageDisp_1_SV` (第3697行)
   - 范围检查也使用：`PowerQuality_Set_Max.VoltageDisp_1_SV` (第3687行)

2. **函数 `dWrite_PowerQuality_VoltageSwell_1_AT` (第3701行)**
   - 函数名：`dWrite_PowerQuality_VoltageSwell_1_AT`
   - 但函数内操作：`PowerQuality_Set.VoltageDisp_1_AT` (第3712行)

3. **函数 `dWrite_PowerQuality_VoltageSwell_2_SV` (第3716行)**
   - 函数内操作：`PowerQuality_Set.VoltageDisp_2_SV`

4. **函数 `dWrite_PowerQuality_VoltageSwell_2_AT` (第3731行)**
   - 函数内操作：`PowerQuality_Set.VoltageDisp_2_AT`

5. **函数 `dWrite_PowerQuality_VoltageSwell_3_SV` (第3746行)**
   - 函数内操作：`PowerQuality_Set.VoltageDisp_3_SV`

6. **函数 `dWrite_PowerQuality_VoltageSwell_3_AT` (第3761行)**
   - 函数内操作：`PowerQuality_Set.VoltageDisp_3_AT`

**影响：**
- 当通过 Modbus 写入地址 0x2400-0x2405 时，数据会被写入到错误的变量（`VoltageDisp_*` 而不是 `VoltageSwell_*`）
- 读取这些地址时，返回的是 `VoltageSwell_*` 的值，但写入时却修改了 `VoltageDisp_*`，导致读写不一致

**修复建议：**
需要确认正确的变量名。有两种修复方案：

**方案1：** 如果应该操作 `VoltageSwell_*` 变量，则修改函数实现：
```c
// 修改 dWrite_PowerQuality_VoltageSwell_1_SV 函数
PowerQuality_Set.VoltageSwell_1_SV = (*pData);  // 而不是 VoltageDisp_1_SV
```

**方案2：** 如果应该操作 `VoltageDisp_*` 变量，则修改 `g_displayMapList` 中的 Memory 字段：
```c
{.Addr = 0x2400, .Memory = &PowerQuality_Set.VoltageDisp_1_SV, ...}
```

## 检查说明

本报告检查了 `g_displayMapList` 中所有带 Handle 回调函数的条目。

检查位置：
- `g_displayMapList` 定义：`app_modbus/app_modbus.c` 第68行开始
- Handle 回调函数实现：`app_modbus/app_modbus_reg.c`
- 底层写入函数：`Parameters/Data_Write.c`

**检查日期：** 2024年
**检查范围：** `g_displayMapList` 中所有有 Handle 回调函数的条目（约167个条目）

