################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/basico.c \
../src/commons.c \
../src/leaks.c \
../src/miNivel.c \
../src/servidor.c \
../src/solucionLeo.c \
../src/tadArchivos.c 

OBJS += \
./src/basico.o \
./src/commons.o \
./src/leaks.o \
./src/miNivel.o \
./src/servidor.o \
./src/solucionLeo.o \
./src/tadArchivos.o 

C_DEPS += \
./src/basico.d \
./src/commons.d \
./src/leaks.d \
./src/miNivel.d \
./src/servidor.d \
./src/solucionLeo.d \
./src/tadArchivos.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


