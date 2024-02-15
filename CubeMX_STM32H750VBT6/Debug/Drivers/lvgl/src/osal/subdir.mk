################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/lvgl/src/osal/lv_cmsis_rtos2.c \
../Drivers/lvgl/src/osal/lv_freertos.c \
../Drivers/lvgl/src/osal/lv_os_none.c \
../Drivers/lvgl/src/osal/lv_pthread.c \
../Drivers/lvgl/src/osal/lv_rtthread.c \
../Drivers/lvgl/src/osal/lv_windows.c 

OBJS += \
./Drivers/lvgl/src/osal/lv_cmsis_rtos2.o \
./Drivers/lvgl/src/osal/lv_freertos.o \
./Drivers/lvgl/src/osal/lv_os_none.o \
./Drivers/lvgl/src/osal/lv_pthread.o \
./Drivers/lvgl/src/osal/lv_rtthread.o \
./Drivers/lvgl/src/osal/lv_windows.o 

C_DEPS += \
./Drivers/lvgl/src/osal/lv_cmsis_rtos2.d \
./Drivers/lvgl/src/osal/lv_freertos.d \
./Drivers/lvgl/src/osal/lv_os_none.d \
./Drivers/lvgl/src/osal/lv_pthread.d \
./Drivers/lvgl/src/osal/lv_rtthread.d \
./Drivers/lvgl/src/osal/lv_windows.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/lvgl/src/osal/%.o Drivers/lvgl/src/osal/%.su Drivers/lvgl/src/osal/%.cyclo: ../Drivers/lvgl/src/osal/%.c Drivers/lvgl/src/osal/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H750xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../User/Inc -I../Drivers/lvgl -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-lvgl-2f-src-2f-osal

clean-Drivers-2f-lvgl-2f-src-2f-osal:
	-$(RM) ./Drivers/lvgl/src/osal/lv_cmsis_rtos2.cyclo ./Drivers/lvgl/src/osal/lv_cmsis_rtos2.d ./Drivers/lvgl/src/osal/lv_cmsis_rtos2.o ./Drivers/lvgl/src/osal/lv_cmsis_rtos2.su ./Drivers/lvgl/src/osal/lv_freertos.cyclo ./Drivers/lvgl/src/osal/lv_freertos.d ./Drivers/lvgl/src/osal/lv_freertos.o ./Drivers/lvgl/src/osal/lv_freertos.su ./Drivers/lvgl/src/osal/lv_os_none.cyclo ./Drivers/lvgl/src/osal/lv_os_none.d ./Drivers/lvgl/src/osal/lv_os_none.o ./Drivers/lvgl/src/osal/lv_os_none.su ./Drivers/lvgl/src/osal/lv_pthread.cyclo ./Drivers/lvgl/src/osal/lv_pthread.d ./Drivers/lvgl/src/osal/lv_pthread.o ./Drivers/lvgl/src/osal/lv_pthread.su ./Drivers/lvgl/src/osal/lv_rtthread.cyclo ./Drivers/lvgl/src/osal/lv_rtthread.d ./Drivers/lvgl/src/osal/lv_rtthread.o ./Drivers/lvgl/src/osal/lv_rtthread.su ./Drivers/lvgl/src/osal/lv_windows.cyclo ./Drivers/lvgl/src/osal/lv_windows.d ./Drivers/lvgl/src/osal/lv_windows.o ./Drivers/lvgl/src/osal/lv_windows.su

.PHONY: clean-Drivers-2f-lvgl-2f-src-2f-osal

