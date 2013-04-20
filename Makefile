CCFLAGS := -I$(CURDIR)/include

TARGETS := all clean distclean disassembly

.PHONY : $(TARGETS)

$(TARGETS):
	$(MAKE) CCFLAGS=$(CCFLAGS) -C src $@

