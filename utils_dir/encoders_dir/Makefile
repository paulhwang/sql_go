##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

ENCODERS_LIB = list_mgr_lib.a
ENCODERS_OBJS = encoders_class.o
clean_make:
	make clean; make all

all:	$(ENCODERS_LIB) $(ENCODERS_OBJS)

$(ENCODERS_LIB): $(ENCODERS_OBJS)
	$(AR) $(ARFLAGS) -r $(ENCODERS_LIB) $(ENCODERS_OBJS)
	$(RANLIB) $(ENCODERS_LIB)

encoders_class.o:	encoders_class.cpp encoders_class.h
	$(GPP) -c encoders_class.cpp

clean: 
	$(RM) $(LIST_MGR_OBJS) $(ENCODERS_OBJS)


