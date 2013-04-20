SUBDIRS := $(wildcard */.)
TARGETS := all clean distclean disassembly

SUBDIRS_TARGETS := \
	$(foreach t,$(TARGETS),$(addsuffix $t,$(SUBDIRS)))

.PHONY : $(TARGETS) $(SUBDIRS_TARGETS)

$(TARGETS) : % : $(addsuffix %,$(SUBDIRS))

$(SUBDIRS_TARGETS) :
	$(MAKE) CCFLAGS=$(CCFLAGS) -C $(@D) $(@F:.%=%)

