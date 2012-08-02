################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Orbital_Sim/CoordinateConversions.cpp \
../Orbital_Sim/Planet.cpp \
../Orbital_Sim/SimControl.cpp \
../Orbital_Sim/SpaceObject.cpp \
../Orbital_Sim/main.cpp 

OBJS += \
./Orbital_Sim/CoordinateConversions.o \
./Orbital_Sim/Planet.o \
./Orbital_Sim/SimControl.o \
./Orbital_Sim/SpaceObject.o \
./Orbital_Sim/main.o 

CPP_DEPS += \
./Orbital_Sim/CoordinateConversions.d \
./Orbital_Sim/Planet.d \
./Orbital_Sim/SimControl.d \
./Orbital_Sim/SpaceObject.d \
./Orbital_Sim/main.d 


# Each subdirectory must supply rules for building sources it contributes
Orbital_Sim/%.o: ../Orbital_Sim/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


