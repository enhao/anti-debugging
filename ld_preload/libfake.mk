SHELL := /bin/sh
TARGET = libfake.so

SOURCES = libfake.c
OBJECTS = $(SOURCES:%.c=%.o)

CC = gcc
LD = gcc

LDFLAGS += -shared -Wl,-soname,$(TARGET)

# GCC verbose option
#CFLAGS += -v
#LDFLAGS += -v

# GCC debugging options
#CFLAGS += -g3 -ggdb3

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(LD) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean distclean

clean:
	$(RM) *.o $(TARGET)

distclean: clean

