################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/widgets/arc/lv_arc.c 

OBJS += \
./Drivers/lvgl/src/widgets/arc/lv_arc.o 

C_DEPS += \
./Drivers/lvgl/src/widgets/arc/lv_arc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/widgets/arc/%.o Drivers/lvgl/src/widgets/arc/%.su Drivers/lvgl/src/widgets/arc/%.cyclo: ../Drivers/lvgl/src/widgets/arc/%.c Drivers/lvgl/src/widgets/arc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-arc

clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-arc:
	-$(RM) ./Drivers/lvgl/src/widgets/arc/lv_arc.cyclo ./Drivers/lvgl/src/widgets/arc/lv_arc.d ./Drivers/lvgl/src/widgets/arc/lv_arc.o ./Drivers/lvgl/src/widgets/arc/lv_arc.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-widgets-2f-arc

