###############################################################
# Global setting
###############################################################

CC = gcc
CX = g++
CCFLAGS = -O2 -Wall -Werror -MMD

COMPILE = $(CCFLAGS) $(addprefix -I,$(INCS)) -c $< -o $@
LINK = $^ -o $@ $(addprefix -L,$(LIBDIRS)) $(addprefix -l,$(LIBS))

###############################################################
# Declare targets
###############################################################

.DEFAULT_GOAL = all

###############################################################
# Auto-dependencies
###############################################################

CCSRCS = $(wildcard *.c)
CXSRCS = $(wildcard *.cpp)
SRCS = $(CCSRCS) $(CXSRCS)
INCS =

OBJS = $(addsuffix .o, $(basename $(SRCS)))
DEPS = $(addsuffix .d, $(basename $(SRCS)))

-include $(DEPS)

###############################################################
# Declare dependencies
###############################################################

GOAL = SGA
LIBS = m
LIBDIRS =

$(GOAL): $(OBJS)
	@printf "  %-8s$@\n" "LINK"
	$(Q)$(CX) $(LINK)

################################################################
# Support make targets
################################################################

.PHONY: all
all: $(GOAL)

.PHONY: clean
clean:
	@printf "  %-8s$(realpath .)\n" "CLEAN"
	$(Q)rm -f $(OBJS) $(DEPS) $(GOAL)

.PHONY: distclean
distclean: clean

%.o: %.cpp
	@printf "  %-8s$@\n" "CX"
	$(Q)$(CX) $(COMPILE)
 
%.o: %.c
	@printf "  %-8s$@\n" "CC"
	$(Q)$(CC) $(COMPILE)

################################################################
# Utils
################################################################

V ?= 0
ifeq ($(V),1)
    Q =
else
    Q = @
endif
