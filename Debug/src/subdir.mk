################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f1xx_it.c \
../src/syscalls.c \
../src/system_stm32f10x.c 

OBJS += \
./src/main.o \
./src/stm32f1xx_it.o \
./src/syscalls.o \
./src/system_stm32f10x.o 

C_DEPS += \
./src/main.d \
./src/stm32f1xx_it.d \
./src/syscalls.d \
./src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -I"C:/Users/obcon/workspaceAC6/ProjektMikro/inc" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/CMSIS/core" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/CMSIS/device" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/StdPeriph_Driver/inc" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/Utilities/STM32F1xx-Nucleo" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


