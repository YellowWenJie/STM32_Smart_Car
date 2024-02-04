################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/JOY/joy.c 

OBJS += \
./User/JOY/joy.o 

C_DEPS += \
./User/JOY/joy.d 


# Each subdirectory must supply rules for building sources it contributes
User/JOY/%.o User/JOY/%.su User/JOY/%.cyclo: ../User/JOY/%.c User/JOY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-JOY

clean-User-2f-JOY:
	-$(RM) ./User/JOY/joy.cyclo ./User/JOY/joy.d ./User/JOY/joy.o ./User/JOY/joy.su

.PHONY: clean-User-2f-JOY

