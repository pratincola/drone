################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl/" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --define=UART_BUFFERED --display_error_number --diag_warning=225 --diag_wrap=off --abi=eabi --preproc_with_compile --preproc_dependency="main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mpu9150.obj: ../mpu9150.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl/" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --define=UART_BUFFERED --display_error_number --diag_warning=225 --diag_wrap=off --abi=eabi --preproc_with_compile --preproc_dependency="mpu9150.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

pid.obj: ../pid.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl/" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --define=UART_BUFFERED --display_error_number --diag_warning=225 --diag_wrap=off --abi=eabi --preproc_with_compile --preproc_dependency="pid.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl/" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --define=UART_BUFFERED --display_error_number --diag_warning=225 --diag_wrap=off --abi=eabi --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


