################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/MCU_Core/syscalls.c \
../Sources/MCU_Core/sysmem.c 

OBJS += \
./Sources/MCU_Core/syscalls.o \
./Sources/MCU_Core/sysmem.o 

C_DEPS += \
./Sources/MCU_Core/syscalls.d \
./Sources/MCU_Core/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/MCU_Core/syscalls.o: ../Sources/MCU_Core/syscalls.c Sources/MCU_Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L431xx -DDEBUG -c -I../Includes -I../Includes/MCU_Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Sources/MCU_Core/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Sources/MCU_Core/sysmem.o: ../Sources/MCU_Core/sysmem.c Sources/MCU_Core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L431xx -DDEBUG -c -I../Includes -I../Includes/MCU_Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Sources/MCU_Core/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

