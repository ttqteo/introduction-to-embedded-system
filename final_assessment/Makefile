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
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# make run
# make run COURSE1=true
# make run VERBOSE=true COURSE=true
# make clean - Clean all built file
#
#------------------------------------------------------------------------------

SHELL=/bin/bash

SRC_DIR := ./src
OBJ_DIR := ./obj
INC_DIR := ./include

SOURCES = $(SRC_DIR)/main.c \
  $(SRC_DIR)/memory.c \
  $(SRC_DIR)/stats.c \
  $(SRC_DIR)/data.c \
  $(SRC_DIR)/course1.c 

INCLUDES = -I include/common/

# Platform Overrides
PLATFORM = HOST

#Compile time switches
COURSE1 = false
VERBOSE = false


# General Flags for all platforms
GEN_FLAGS = -Wall \
	    -g \
	    -O0 \
	    -std=c99

TARGET = final


# Architectures Specific Flags & Compiler Flags and Defines
ifeq ($(PLATFORM),MSP432)
  CPU = cortex-m4
  RCH = armv7e-m
  
  SOURCES+= ./startup_msp432p401r_gcc.c \
 	    ./system_msp432p401r.c \
	    ./interrupts_msp432p401r_gcc.c

  INCLUDES+= -I include/CMSIS/ \
	     -I include/msp432/

  CC = arm-none-eabi-gcc

  LD = arm-none-eabi-ld
  SIZE = arm-none-eabi-size

  LINKER_FILE = ../msp432p401r.lds
  LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE) -lm

  CFLAGS = $(GEN_FLAGS) \
	   -mcpu=$(CPU) \
	   -mthumb \
	   -march=$(ARCH) \
	   -mfloat-abi=hard \
	   -mfpu=fpv4-sp-d16\
	   --specs=nosys.specs

  CPPFLAGS = -DMSP432 $(INCLUDES)

else
  CC = gcc
  CFLAGS = $(GEN_FLAGS)
  CPPFLAGS = -DHOST $(INCLUDES)
  SIZE = size
  LDFLAGS = -lm
endif

# If COURSE1 is defined
ifeq ($(COURSE1), true)
  CPPFLAGS += -DCOURSE1
endif

# If VERBOSE is defined
ifeq ($(VERBOSE), true)
  CPPFLAGS += -DVERBOSE
endif


# More Declared Variables

PREP = $(SOURCES:.c=.i)	# Preprocessor Files
DEPS = $(SOURCES:.c=.d)	# Dependancy Files
ASMS = $(SOURCES:.c=.asm) # Assembly Files
OBJS = $(SOURCES:.c=.o)	# Object files

.PHONY: compile-all build clean run


# Compile all object files and link into a final executable.

build: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@


# Generate the preprocessed output of all file

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate assembly output of all file

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate Object file to Compile

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

# Generate Dependancy files for each Source File
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@


# Compile all object files, but DO NOT link.
compile-all: $(OBJS)

clean:
	# This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
	@echo Removing all built files
	rm -f ${SRC_DIR}/*{.o,.out,.map,.asm,.i} $(TARGET).out

# Build all and run file
run: $(TARGET).out
	./$(TARGET).out
