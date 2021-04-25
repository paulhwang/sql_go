##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

CORE_LIB = core.a
CORE_OBJS = root_class.o raw_api_class.o

$(CORE_LIB): $(CORE_OBJS)
	$(AR) $(ARFLAGS) -r $(CORE_LIB) $(CORE_OBJS)
	$(RANLIB) $(CORE_LIB)

root_class.o:	root_class.cpp root_class.h
	$(GPP) -c root_class.cpp

raw_api_class.o:	raw_api_class.cpp raw_api_class.h
	$(GPP) -c raw_api_class.cpp

clean: 
	$(RM) $(CORE_LIB); $(RM) $(CORE_OBJS)

