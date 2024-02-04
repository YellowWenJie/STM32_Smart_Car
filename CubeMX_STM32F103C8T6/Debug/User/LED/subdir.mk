################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/LED/led.c 

OBJS += \
./User/LED/led.o 

C_DEPS += \
./User/LED/led.d 


# Each subdirectory must supply rules for building sources it contributes
User/LED/%.o User/LED/%.su User/LED/%.cyclo: ../User/LED/%.c User/LED/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-LED

clean-User-2f-LED:
	-$(RM) ./User/LED/led.cyclo ./User/LED/led.d ./User/LED/led.o ./User/LED/led.su

.PHONY: clean-User-2f-LED

