##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

ABEND_DIR = abend
ABEND_OBJS = $(ABEND_DIR)/abend_class.o

QUEUE_DIR = queue
QUEUE_OBJS = $(QUEUE_DIR)/queue_entry_class.o $(QUEUE_DIR)/list_queue_class.o 
#QUEUE_OBJS = queue.a

UTILS_LIB = utils.a
UTILS_OBJS = utils_class.o  $(ABEND_OBJS) $(QUEUE_OBJS)

$(UTILS_LIB): $(UTILS_OBJS)
	$(AR) $(ARFLAGS) -r $(UTILS_LIB) $(UTILS_OBJS)
	$(RANLIB) $(UTILS_LIB)
	
utils_class.o: utils_class.cpp utils_class.h
	$(GPP) -c utils_class.cpp

$(ABEND_OBJS):
		cd $(ABEND_DIR); make clear; make; cd ..

$(QUEUE_OBJS):
		cd $(QUEUE_DIR); make clear; make; cd ..

clean: 
	$(RM) $(UTILS_LIB); $(RM) $(UTILS_OBJS)

