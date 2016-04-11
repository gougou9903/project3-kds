################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/buffer.c \
../Sources/ftoa.c \
../Sources/itoa.c \
../Sources/log.c \
../Sources/main.c \
../Sources/uart.c \
../Sources/unit_test.c \
../Sources/utils.c 

OBJS += \
./Sources/buffer.o \
./Sources/ftoa.o \
./Sources/itoa.o \
./Sources/log.o \
./Sources/main.o \
./Sources/uart.o \
./Sources/unit_test.o \
./Sources/utils.o 

C_DEPS += \
./Sources/buffer.d \
./Sources/ftoa.d \
./Sources/itoa.d \
./Sources/log.d \
./Sources/main.d \
./Sources/uart.d \
./Sources/unit_test.d \
./Sources/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


