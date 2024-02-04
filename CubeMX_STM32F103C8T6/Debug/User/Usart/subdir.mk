################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Usart/usart.c 

OBJS += \
./User/Usart/usart.o 

C_DEPS += \
./User/Usart/usart.d 


# Each subdirectory must supply rules for building sources it contributes
User/Usart/%.o User/Usart/%.su User/Usart/%.cyclo: ../User/Usart/%.c User/Usart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-User-2f-Usart

clean-User-2f-Usart:
	-$(RM) ./User/Usart/usart.cyclo ./User/Usart/usart.d ./User/Usart/usart.o ./User/Usart/usart.su

.PHONY: clean-User-2f-Usart

