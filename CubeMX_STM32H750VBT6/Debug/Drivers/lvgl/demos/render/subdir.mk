################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/demos/render/lv_demo_render.c 

OBJS += \
./Drivers/lvgl/demos/render/lv_demo_render.o 

C_DEPS += \
./Drivers/lvgl/demos/render/lv_demo_render.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/demos/render/%.o Drivers/lvgl/demos/render/%.su Drivers/lvgl/demos/render/%.cyclo: ../Drivers/lvgl/demos/render/%.c Drivers/lvgl/demos/render/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-demos-2f-render

clean-Drivers-2f-lvgl-2f-demos-2f-render:
	-$(RM) ./Drivers/lvgl/demos/render/lv_demo_render.cyclo ./Drivers/lvgl/demos/render/lv_demo_render.d ./Drivers/lvgl/demos/render/lv_demo_render.o ./Drivers/lvgl/demos/render/lv_demo_render.su

.PHONY: clean-Drivers-2f-lvgl-2f-demos-2f-render

