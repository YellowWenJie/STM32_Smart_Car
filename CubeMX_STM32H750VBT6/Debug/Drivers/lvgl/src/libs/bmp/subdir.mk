################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/bmp/lv_bmp.c 

OBJS += \
./Drivers/lvgl/src/libs/bmp/lv_bmp.o 

C_DEPS += \
./Drivers/lvgl/src/libs/bmp/lv_bmp.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/bmp/%.o Drivers/lvgl/src/libs/bmp/%.su Drivers/lvgl/src/libs/bmp/%.cyclo: ../Drivers/lvgl/src/libs/bmp/%.c Drivers/lvgl/src/libs/bmp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-bmp

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-bmp:
	-$(RM) ./Drivers/lvgl/src/libs/bmp/lv_bmp.cyclo ./Drivers/lvgl/src/libs/bmp/lv_bmp.d ./Drivers/lvgl/src/libs/bmp/lv_bmp.o ./Drivers/lvgl/src/libs/bmp/lv_bmp.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-bmp

