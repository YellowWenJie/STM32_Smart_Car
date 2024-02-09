################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/Src/lcd_169.c \
../User/Src/lcd_fonts.c \
../User/Src/led.c 

OBJS += \
./User/Src/lcd_169.o \
./User/Src/lcd_fonts.o \
./User/Src/led.o 

C_DEPS += \
./User/Src/lcd_169.d \
./User/Src/lcd_fonts.d \
./User/Src/led.d 


# Each subdirectory must supply rules for building sources it contributes
User/Src/%.o User/Src/%.su User/Src/%.cyclo: ../User/Src/%.c User/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-User-2f-Src

clean-User-2f-Src:
	-$(RM) ./User/Src/lcd_169.cyclo ./User/Src/lcd_169.d ./User/Src/lcd_169.o ./User/Src/lcd_169.su ./User/Src/lcd_fonts.cyclo ./User/Src/lcd_fonts.d ./User/Src/lcd_fonts.o ./User/Src/lcd_fonts.su ./User/Src/led.cyclo ./User/Src/led.d ./User/Src/led.o ./User/Src/led.su

.PHONY: clean-User-2f-Src

