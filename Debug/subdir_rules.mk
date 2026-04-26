################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xyx/workspace_ccstheia/car" -I"C:/Users/xyx/workspace_ccstheia/car/Debug" -I"D:/ti/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_06_00_05/source" -I"C:/Users/xyx/workspace_ccstheia/car/my_drivers/Inc" -I"C:/Users/xyx/workspace_ccstheia/car/PID/Inc" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-474282299: ../empty.syscfg
	@echo 'SysConfig - building file: "$<"'
	"D:/ti/ccs2020/ccs/utils/sysconfig_1.25.0/sysconfig_cli.bat" -s "D:/ti/mspm0_sdk_2_06_00_05/.metadata/product.json" --script "C:/Users/xyx/workspace_ccstheia/car/empty.syscfg" -o "." --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-474282299 ../empty.syscfg
device.opt: build-474282299
device.cmd.genlibs: build-474282299
ti_msp_dl_config.c: build-474282299
ti_msp_dl_config.h: build-474282299
Event.dot: build-474282299

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xyx/workspace_ccstheia/car" -I"C:/Users/xyx/workspace_ccstheia/car/Debug" -I"D:/ti/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_06_00_05/source" -I"C:/Users/xyx/workspace_ccstheia/car/my_drivers/Inc" -I"C:/Users/xyx/workspace_ccstheia/car/PID/Inc" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g351x_ticlang.o: D:/ti/mspm0_sdk_2_06_00_05/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g351x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"D:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/xyx/workspace_ccstheia/car" -I"C:/Users/xyx/workspace_ccstheia/car/Debug" -I"D:/ti/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"D:/ti/mspm0_sdk_2_06_00_05/source" -I"C:/Users/xyx/workspace_ccstheia/car/my_drivers/Inc" -I"C:/Users/xyx/workspace_ccstheia/car/PID/Inc" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


