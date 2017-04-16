################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TAddress.cpp \
../TDate.cpp \
../TLocation.cpp \
../TPerson.cpp \
../TTime.cpp \
../Ueb2.cpp 

OBJS += \
./TAddress.o \
./TDate.o \
./TLocation.o \
./TPerson.o \
./TTime.o \
./Ueb2.o 

CPP_DEPS += \
./TAddress.d \
./TDate.d \
./TLocation.d \
./TPerson.d \
./TTime.d \
./Ueb2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


