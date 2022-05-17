################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/aspep.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/main.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_api.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_config.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_configuration_registers.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_interface.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_math.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_parameters.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_tasks.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mcp_config.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/motorcontrol.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/pwm_curr_fdbk.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/register_interface.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/regular_conversion_manager.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_hal_msp.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_it.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_mc_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/usart_aspep_driver.c 

OBJS += \
./Application/User/aspep.o \
./Application/User/main.o \
./Application/User/mc_api.o \
./Application/User/mc_config.o \
./Application/User/mc_configuration_registers.o \
./Application/User/mc_interface.o \
./Application/User/mc_math.o \
./Application/User/mc_parameters.o \
./Application/User/mc_tasks.o \
./Application/User/mcp_config.o \
./Application/User/motorcontrol.o \
./Application/User/pwm_curr_fdbk.o \
./Application/User/register_interface.o \
./Application/User/regular_conversion_manager.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_it.o \
./Application/User/stm32f4xx_mc_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/usart_aspep_driver.o 

C_DEPS += \
./Application/User/aspep.d \
./Application/User/main.d \
./Application/User/mc_api.d \
./Application/User/mc_config.d \
./Application/User/mc_configuration_registers.d \
./Application/User/mc_interface.d \
./Application/User/mc_math.d \
./Application/User/mc_parameters.d \
./Application/User/mc_tasks.d \
./Application/User/mcp_config.d \
./Application/User/motorcontrol.d \
./Application/User/pwm_curr_fdbk.d \
./Application/User/register_interface.d \
./Application/User/regular_conversion_manager.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_it.d \
./Application/User/stm32f4xx_mc_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/usart_aspep_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/aspep.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/aspep.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/main.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_api.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_api.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_config.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_config.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_configuration_registers.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_configuration_registers.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_interface.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_math.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_math.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_parameters.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_parameters.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mc_tasks.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mc_tasks.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/mcp_config.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/mcp_config.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/motorcontrol.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/motorcontrol.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/pwm_curr_fdbk.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/pwm_curr_fdbk.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/register_interface.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/register_interface.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/regular_conversion_manager.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/regular_conversion_manager.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/stm32f4xx_hal_msp.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/stm32f4xx_it.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/stm32f4xx_mc_it.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/stm32f4xx_mc_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/%.o Application/User/%.su: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Application/User/usart_aspep_driver.o: E:/app/julia/ebf_motor_tutorial_code_stm32f407_jiaoyang/improve_part2/BLDC_FOC_V5.Y.2_Hall_speed_control/BLDC_control/Src/usart_aspep_driver.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DARM_MATH_CM4 -DDEBUG -DSTM32F407xx -c -I../../Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/Any/Inc -I../../MCSDK_v5.Y.2-Full/MotorControl/MCSDK/MCLib/F4xx/Inc -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../Drivers/CMSIS/Include -I../../Drivers/CMSIS/DSP/Include -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/aspep.d ./Application/User/aspep.o ./Application/User/aspep.su ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/mc_api.d ./Application/User/mc_api.o ./Application/User/mc_api.su ./Application/User/mc_config.d ./Application/User/mc_config.o ./Application/User/mc_config.su ./Application/User/mc_configuration_registers.d ./Application/User/mc_configuration_registers.o ./Application/User/mc_configuration_registers.su ./Application/User/mc_interface.d ./Application/User/mc_interface.o ./Application/User/mc_interface.su ./Application/User/mc_math.d ./Application/User/mc_math.o ./Application/User/mc_math.su ./Application/User/mc_parameters.d ./Application/User/mc_parameters.o ./Application/User/mc_parameters.su ./Application/User/mc_tasks.d ./Application/User/mc_tasks.o ./Application/User/mc_tasks.su ./Application/User/mcp_config.d ./Application/User/mcp_config.o ./Application/User/mcp_config.su ./Application/User/motorcontrol.d ./Application/User/motorcontrol.o ./Application/User/motorcontrol.su ./Application/User/pwm_curr_fdbk.d ./Application/User/pwm_curr_fdbk.o ./Application/User/pwm_curr_fdbk.su ./Application/User/register_interface.d ./Application/User/register_interface.o ./Application/User/register_interface.su ./Application/User/regular_conversion_manager.d ./Application/User/regular_conversion_manager.o ./Application/User/regular_conversion_manager.su ./Application/User/stm32f4xx_hal_msp.d ./Application/User/stm32f4xx_hal_msp.o ./Application/User/stm32f4xx_hal_msp.su ./Application/User/stm32f4xx_it.d ./Application/User/stm32f4xx_it.o ./Application/User/stm32f4xx_it.su ./Application/User/stm32f4xx_mc_it.d ./Application/User/stm32f4xx_mc_it.o ./Application/User/stm32f4xx_mc_it.su ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/usart_aspep_driver.d ./Application/User/usart_aspep_driver.o ./Application/User/usart_aspep_driver.su

.PHONY: clean-Application-2f-User

