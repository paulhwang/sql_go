##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

QUEUE_LIB = queue_lib.a
QUEUE_OBJS = queue_entry_class.o list_queue_class.o

clean_make:
	make clean; make all

all:	$(QUEUE_LIB) $(QUEUE_OBJS)

$(QUEUE_LIB): $(QUEUE_OBJS)
	$(AR) $(ARFLAGS) -r $(QUEUE_LIB) $(QUEUE_OBJS)
	$(RANLIB) $(QUEUE_LIB)

queue_entry_class.o:	queue_entry_class.cpp queue_entry_class.h
	$(GPP) -c queue_entry_class.cpp

list_queue_class.o:	list_queue_class.cpp list_queue_class.h
	$(GPP) -c list_queue_class.cpp

clean: 
	$(RM) $(QUEUE_OBJS) $(QUEUE_LIB)


