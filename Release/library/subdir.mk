################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library/fileIO.cpp \
../library/library.cpp 

OBJS += \
./library/fileIO.o \
./library/library.o 

CPP_DEPS += \
./library/fileIO.d \
./library/library.d 


# Each subdirectory must supply rules for building sources it contributes
library/%.o: ../library/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


