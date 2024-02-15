################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.c 

OBJS += \
./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.o 

C_DEPS += \
./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/libs/ffmpeg/%.o Drivers/lvgl/src/libs/ffmpeg/%.su Drivers/lvgl/src/libs/ffmpeg/%.cyclo: ../Drivers/lvgl/src/libs/ffmpeg/%.c Drivers/lvgl/src/libs/ffmpeg/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-ffmpeg

clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-ffmpeg:
	-$(RM) ./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.cyclo ./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.d ./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.o ./Drivers/lvgl/src/libs/ffmpeg/lv_ffmpeg.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-libs-2f-ffmpeg

