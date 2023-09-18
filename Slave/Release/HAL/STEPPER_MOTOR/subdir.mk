################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/STEPPER_MOTOR/STEPPER_program.c 

OBJS += \
./HAL/STEPPER_MOTOR/STEPPER_program.o 

C_DEPS += \
./HAL/STEPPER_MOTOR/STEPPER_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/STEPPER_MOTOR/%.o: ../HAL/STEPPER_MOTOR/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


