################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/hardware.c \
../Sources/isr.c \
../Sources/main.c 

OBJS += \
./Sources/hardware.o \
./Sources/isr.o \
./Sources/main.o 

C_DEPS += \
./Sources/hardware.d \
./Sources/isr.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/hardware.o: ../Sources/hardware.c Sources/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L431xx -DDEBUG -c -I../Includes -I../Includes/MCU_Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Sources/hardware.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Sources/isr.o: ../Sources/isr.c Sources/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L431xx -DDEBUG -c -I../Includes -I../Includes/MCU_Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Sources/isr.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Sources/main.o: ../Sources/main.c Sources/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32L431xx -DDEBUG -c -I../Includes -I../Includes/MCU_Core -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Sources/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

