SHELL := /bin/bash
TARGET = ld_preload
LIBFAKE = libfake.so

GDB = gdb


all: $(TARGET) $(LIBFAKE)

$(TARGET):
	$(MAKE) -f ld_preload.mk

$(LIBFAKE):
	$(MAKE) -f libfake.mk

.PONY: gdb clean distclean

gdb: $(TARGET) $(LIBFAKE)
	$(GDB) -iex "set exec-wrapper env LD_PRELOAD=$(LIBFAKE)" $(TARGET)

clean:
	$(MAKE) -f ld_preload.mk clean
	$(MAKE) -f libfake.mk clean

distclean:
	$(MAKE) -f ld_preload.mk distclean
	$(MAKE) -f libfake.mk distclean
