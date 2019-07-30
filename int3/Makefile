SHELL := /bin/sh
TARGET = int3

SOURCES = int3.c
OBJECTS = $(SOURCES:%.c=%.o)

CC = gcc
LD = gcc
GDB = gdb

# GCC verbose option
#CFLAGS += -v
#LDFLAGS += -v

# GCC debugging options
#CFLAGS += -g3 -ggdb3

# Common common definitions
#ENV_DIR = $(realpath $HOME/glibc/env)
#GLIBC_VER = 2.27

# Interpreter
#INTERPRETER = $(ENV_DIR)/glibc-$(GLIBC_VER)/sysroot/lib/ld.so)
#LDFLAGS += -Wl,--dynamic-linker=$(INTERPRETER)

# GDB
#GLIBC_DIR = $(ENV_DIR)/build/glibc-$(GLIBC_VER)
#GDBOPT_DIRECTORY = --directory="$(GLIBC_DIR):$\
#$(GLIBC_DIR)/csu:$\
#$(GLIBC_DIR)/elf:$\
#$(GLIBC_DIR)/stdlib"

GDBOPTS = -q $(GDBOPT_DIRECTORY)


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

gdb: $(TARGET)
	$(GDB) $(GDBOPTS) $(TARGET)

.PHONY: clean distclean

clean:
	$(RM) *.o $(TARGET)

distclean: clean
	$(RM) peda-session-*.txt .gdb_history

