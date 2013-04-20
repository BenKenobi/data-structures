CC      := g++
#TARGET	:= array_list
SRCS    := array_list.cpp
OBJS    := $(SRCS:.cpp=.o)
DISS	:= $(OBJS:.o=.dis)
DISASS	:= objdump -S
TOP	:= ../../../..
MOD_PATH:= it/ds/list

CCFLAGS += -g3
LDFLAGS +=
LIBS    +=

.PHONY: all clean distclean disassembly

all: $(OBJS)

#$(TARGET): $(OBJS)
#	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJS): %.o: %.cpp
	$(CC) $(CCFLAGS) -o $@ -c $<
	mv *.o $(TOP)/obj/$(MOD_PATH)

clean:
	rm -f *~
	rm -f $(TOP)/obj/$(MOD_PATH)/*.o $(TOP)/obj/$(MOD_PATH)/*.dis

distclean: clean
	rm -f $(TOP)/bin/$(TARGET)

disassembly:
	$(DISASS) $(TOP)/obj/$(MOD_PATH)/$(OBJS) > $(TOP)/obj/$(MOD_PATH)/$(DISS)


