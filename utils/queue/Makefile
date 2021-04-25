##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

QUEUE_LIB = ../queue.a
QUEUE_OBJS = queue_entry_class.o list_queue_class.o

$(QUEUE_LIB): $(QUEUE_OBJS)
	$(AR) $(ARFLAGS) -r $(QUEUE_LIB) $(QUEUE_OBJS)
	$(RANLIB) $(QUEUE_LIB)

queue_entry_class.o:	queue_entry_class.cpp queue_entry_class.h
	$(GPP) -c queue_entry_class.cpp

list_queue_class.o:	list_queue_class.cpp list_queue_class.h
	$(GPP) -c list_queue_class.cpp

clean: 
	$(RM) $(QUEUE_OBJS)


