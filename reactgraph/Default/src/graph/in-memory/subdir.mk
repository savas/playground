################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/graph/in-memory/InMemoryReactiveEdge.cpp \
../src/graph/in-memory/InMemoryReactiveNode.cpp 

OBJS += \
./src/graph/in-memory/InMemoryReactiveEdge.o \
./src/graph/in-memory/InMemoryReactiveNode.o 

CPP_DEPS += \
./src/graph/in-memory/InMemoryReactiveEdge.d \
./src/graph/in-memory/InMemoryReactiveNode.d 


# Each subdirectory must supply rules for building sources it contributes
src/graph/in-memory/%.o: ../src/graph/in-memory/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I/Users/savasp/dev/ext/boost/include -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


