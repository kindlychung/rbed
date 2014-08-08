################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RcppExports.cpp \
../src/ncols.cpp \
../src/readbed.cpp \
../src/readcols.cpp 

O_SRCS += \
../src/RcppExports.o \
../src/ncols.o \
../src/readbed.o \
../src/readcols.o 

OBJS += \
./src/RcppExports.o \
./src/ncols.o \
./src/readbed.o \
./src/readcols.o 

CPP_DEPS += \
./src/RcppExports.d \
./src/ncols.d \
./src/readbed.d \
./src/readcols.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++1y -I/Library/Frameworks/R.framework/Versions/3.1/Resources/include -I/Library/Frameworks/R.framework/Versions/3.1/Resources/library/Rcpp/include -I/Library/Frameworks/R.framework/Versions/3.1/Resources/library/RcppArmadillo/include -O0 -Wall -c -fmessage-length=0 -arch x86_64 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


