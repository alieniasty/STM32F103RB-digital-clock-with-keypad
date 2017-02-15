################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../startup/startup_stm32f10x_md.S 

OBJS += \
./startup/startup_stm32f10x_md.o 

S_UPPER_DEPS += \
./startup/startup_stm32f10x_md.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -DSTM32F1 -DNUCLEO_F103RB -DSTM32F103RBTx -DSTM32 -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F10X_MD -I"C:/Users/obcon/workspaceAC6/ProjektMikro/inc" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/CMSIS/core" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/CMSIS/device" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/StdPeriph_Driver/inc" -I"C:/Users/obcon/workspaceAC6/ProjektMikro/Utilities/STM32F1xx-Nucleo" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


