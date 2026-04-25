################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
my_drivers/Src/%.o: ../my_drivers/Src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"C:/ti/ccs2031/ccs/tools/compiler/ti-cgt-armllvm_4.0.4.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O2 -I"C:/Users/33548/workspace_ccstheia/empty_LP_MSPM0G3519_nortos_ticlang" -I"C:/Users/33548/workspace_ccstheia/empty_LP_MSPM0G3519_nortos_ticlang/Debug" -I"C:/ti/mspm0_sdk_2_06_00_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_06_00_05/source" -I"C:/Users/33548/workspace_ccstheia/empty_LP_MSPM0G3519_nortos_ticlang/my_drivers/Inc" -gdwarf-3 -MMD -MP -MF"my_drivers/Src/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


