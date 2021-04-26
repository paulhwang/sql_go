##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

LIST_MGR_LIB = list_mgr_lib.a
LIST_MGR_OBJS = list_entry_class.o list_mgr_class.o

clean_make:
	make clean; make all

all:	$(LIST_MGR_LIB) $(LIST_MGR_OBJS)

$(LIST_MGR_LIB): $(LIST_MGR_OBJS)
	$(AR) $(ARFLAGS) -r $(LIST_MGR_LIB) $(LIST_MGR_OBJS)
	$(RANLIB) $(LIST_MGR_LIB)

list_entry_class.o:	list_entry_class.cpp list_entry_class.h
	$(GPP) -c list_entry_class.cpp

list_mgr_class.o:	list_mgr_class.cpp list_mgr_class.h
	$(GPP) -c list_mgr_class.cpp

clean: 
	$(RM) $(LIST_MGR_OBJS) $(LIST_MGR_LIB)


