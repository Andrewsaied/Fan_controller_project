################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Program.c \
../DC_Motor.c \
../GPIO_Program.c \
../LCD_Program.c \
../Timer0.c \
../lm35_sensor.c \
../main.c 

OBJS += \
./ADC_Program.o \
./DC_Motor.o \
./GPIO_Program.o \
./LCD_Program.o \
./Timer0.o \
./lm35_sensor.o \
./main.o 

C_DEPS += \
./ADC_Program.d \
./DC_Motor.d \
./GPIO_Program.d \
./LCD_Program.d \
./Timer0.d \
./lm35_sensor.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


