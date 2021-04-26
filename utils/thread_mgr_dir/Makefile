##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

THREAD_MGR_LIB = thread_mgr_lib.a
THREAD_MGR_OBJS = thread_mgr_class.o thread_entity_class.o

clean_make:
	make clean; make all

all:	$(THREAD_MGR_LIB) $(THREAD_MGR_OBJS)

$(THREAD_MGR_LIB): $(THREAD_MGR_OBJS)
	$(AR) $(ARFLAGS) -r $(THREAD_MGR_LIB) $(THREAD_MGR_OBJS)
	$(RANLIB) $(THREAD_MGR_LIB)

thread_mgr_class.o:	thread_mgr_class.cpp thread_mgr_class.h
	$(GPP) -c thread_mgr_class.cpp

thread_entry_class.o:	thread_entry_class.cpp thread_entry_class.h
	$(GPP) -c thread_entry_class.cpp

clean: 
	$(RM) $(THREAD_MGR_OBJS) $(THREAD_MGR_LIB)


