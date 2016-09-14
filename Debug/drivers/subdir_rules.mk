################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
drivers/rgb.obj: /Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub/drivers/rgb.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl/" --include_path="/Users/pratik1/UT-classes/finalProject/ti/TivaWare_C_Series-2.1.2.111/examples/boards/ek-tm4c123gxl-boostxl-senshub" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --define=TARGET_IS_TM4C123_RB1 --define=UART_BUFFERED --display_error_number --diag_warning=225 --diag_wrap=off --abi=eabi --preproc_with_compile --preproc_dependency="drivers/rgb.d" --obj_directory="drivers" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


