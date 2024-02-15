################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/others/file_explorer/lv_file_explorer.c 

OBJS += \
./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.o 

C_DEPS += \
./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/others/file_explorer/%.o Drivers/lvgl/src/others/file_explorer/%.su Drivers/lvgl/src/others/file_explorer/%.cyclo: ../Drivers/lvgl/src/others/file_explorer/%.c Drivers/lvgl/src/others/file_explorer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-others-2f-file_explorer

clean-Drivers-2f-lvgl-2f-src-2f-others-2f-file_explorer:
	-$(RM) ./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.cyclo ./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.d ./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.o ./Drivers/lvgl/src/others/file_explorer/lv_file_explorer.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-others-2f-file_explorer

