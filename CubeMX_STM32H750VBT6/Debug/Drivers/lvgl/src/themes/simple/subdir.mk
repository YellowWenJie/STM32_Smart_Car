################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/themes/simple/lv_theme_simple.c 

OBJS += \
./Drivers/lvgl/src/themes/simple/lv_theme_simple.o 

C_DEPS += \
./Drivers/lvgl/src/themes/simple/lv_theme_simple.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/themes/simple/%.o Drivers/lvgl/src/themes/simple/%.su Drivers/lvgl/src/themes/simple/%.cyclo: ../Drivers/lvgl/src/themes/simple/%.c Drivers/lvgl/src/themes/simple/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-themes-2f-simple

clean-Drivers-2f-lvgl-2f-src-2f-themes-2f-simple:
	-$(RM) ./Drivers/lvgl/src/themes/simple/lv_theme_simple.cyclo ./Drivers/lvgl/src/themes/simple/lv_theme_simple.d ./Drivers/lvgl/src/themes/simple/lv_theme_simple.o ./Drivers/lvgl/src/themes/simple/lv_theme_simple.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-themes-2f-simple

