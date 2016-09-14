################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ej1.c \
../src/ej4.c \
../src/ej5.c \
../src/sincronizacion.c 

OBJS += \
./src/ej1.o \
./src/ej4.o \
./src/ej5.o \
./src/sincronizacion.o 

C_DEPS += \
./src/ej1.d \
./src/ej4.d \
./src/ej5.d \
./src/sincronizacion.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


