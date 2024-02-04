################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/NRF24L01/nrf24l01.c 

OBJS += \
./User/NRF24L01/nrf24l01.o 

C_DEPS += \
./User/NRF24L01/nrf24l01.d 


# Each subdirectory must supply rules for building sources it contributes
User/NRF24L01/%.o User/NRF24L01/%.su User/NRF24L01/%.cyclo: ../User/NRF24L01/%.c User/NRF24L01/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-NRF24L01

clean-User-2f-NRF24L01:
	-$(RM) ./User/NRF24L01/nrf24l01.cyclo ./User/NRF24L01/nrf24l01.d ./User/NRF24L01/nrf24l01.o ./User/NRF24L01/nrf24l01.su

.PHONY: clean-User-2f-NRF24L01

