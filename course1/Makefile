#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This is a makefile that can compile multiple source files and support two platform targets
# with thier own specific compiler and flags . 
# These two platforms are the HOST and the MSP432. 
# The host embedded system will use the native compiler, gcc. 
# The target embedded system will use the cross compiler, arm-none-eabi-gcc.
# The target platform must be provided at the command line with the make command to set the 
# platform you are compiling for.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
# @HOST we use gcc compiler for the host and ansi c99 standard
# @The host embedded system (MSP432) we use arm-none-eabi-gcc compiler for it and ansi c99 std
# target cpu is cortex-m4 and it's archeticture is thumb armv7e-m float-abi=hard
# mfpu=fpv4-sp-d16 and it's specs is nosys.specs
#
# Platform Overrides:
# @The HOST machine is the defualt platform
# @The HOST embedded system MSP432
#
#------------------------------------------------------------------------------
include sources.mk
 #linker file directory
LINKER_FILE = msp432p401r.lds
 #this is the target output name
TARGET=final
 #defualt PLATFORM
PLATFORM=HOST
 #courses compile time switch
COURSE=COURSE1
 #printing compile time switch
PRINT=VERBOSE
 #common flags in both platforms
COM_FLAGS= -Wall -Werror -std=c99 -g -O0 $(INCLUDES) -D$(PLATFORM) -D$(COURSE) -D$(PRINT)
 #rename every .c to .o file and store it in the variable OBJS
OBJS=$(SOURCES:.c=.o)
 #preprocessor flags to generate .d dependency files
CPPFLAGS= -MMD -MP
 #Architectures Specific Flags
CPU=cortex-m4
ARCH=thumb
ARCH_=armv7e-m
FLOAT_ABI=hard
FPU=fpv4-sp-d16
SPECS=nosys.specs

DIR=src/
 #if PLATFORM=MSP432
ifeq ($(PLATFORM) ,MSP432)
 #Compiler Flags and Defines
CC = arm-none-eabi-gcc
 #Size utility
SIZE=arm-none-eabi-size
LD = arm-none-eabi-ld
 # @LDFLAGS generate map file and use linker file
LDFLAGS = -T $(LINKER_FILE) -Wl,-Map=$(TARGET).map
 # @CFLAGS add include (files.h) directory and specifie the compiler flags
CFLAGS = $(COM_FLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) \
	-mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI) -march=$(ARCH_) 

 #if PLATFORM=HOST
else
 #Compiler Flags and Defines
CC = gcc
 #Size utility
SIZE=size
 # @LDFLAGS generates map file 
LDFLAGS = -Wl,-Map=$(TARGET).map 
 # @CFLAGS add include (files.h) directory and specify the compiler flags
CFLAGS = $(COM_FLAGS)

endif

 # $< dependencies , $@ target to be built
 #  %target to be built : % it's dependencies
%.i : $(DIR)%.c
 #rule to build and it must start with a tab
	$(CC) -E $< $(CFLAGS) -o $@ 

%.asm : $(DIR)%.c
	$(CC) -S $< $(CFLAGS) -o $@ 

%.o : $(DIR)%.c
	$(CC) -MMD -MP -c -o $@ $< $(CFLAGS)

 #PHONY protection to not confuse target name with an actual file 
 #so we could use the command  "make compile-all"
.PHONY: compile-all
compile-all: $(OBJS)

 #so we could use the command  "make build"
.PHONY: build
build: all

 #so we could use the command  "make all"
.PHONY: all
all: $(TARGET).out

 #link and use code size utility
$(TARGET).out:$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -lm
	$(SIZE) -td $@

 #so we could use the command "make clean" to clean all that files
.PHONY: clean
clean:
	rm -f *.o *.map *.out *.asm *.i *.d

