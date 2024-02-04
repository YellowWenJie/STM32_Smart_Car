################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Motor/motor.c 

OBJS += \
./User/Motor/motor.o 

C_DEPS += \
./User/Motor/motor.d 


# Each subdirectory must supply rules for building sources it contributes
User/Motor/%.o User/Motor/%.su User/Motor/%.cyclo: ../User/Motor/%.c User/Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Motor

clean-User-2f-Motor:
	-$(RM) ./User/Motor/motor.cyclo ./User/Motor/motor.d ./User/Motor/motor.o ./User/Motor/motor.su

.PHONY: clean-User-2f-Motor

