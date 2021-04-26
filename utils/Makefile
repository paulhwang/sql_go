##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

ABEND_DIR = abend_dir
ABEND_OBJS = $(ABEND_DIR)/abend_class.o

QUEUE_MGR_DIR = queue_mgr_dir
QUEUE_MGR_OBJS = $(QUEUE_MGR_DIR)/queue_entry_class.o $(QUEUE_MGR_DIR)/list_queue_class.o 

THREAD_MGR_DIR = thread_mgr_dir
THREAD_MGR_OBJS = $(THREAD_MGR_DIR)/thread_entity_class.o $(THREAD_MGR_DIR)/thread_mgr_class.o 

UTILS_LIB = utils.a
UTILS_OBJS = utils_class.o  $(ABEND_OBJS) $(QUEUE_MGR_OBJS) $(THREAD_MGR_OBJS)

clean_make:
	make clean; make all

all: $(UTILS_LIB)

$(UTILS_LIB): $(UTILS_OBJS)
	$(AR) $(ARFLAGS) -r $(UTILS_LIB) $(UTILS_OBJS)
	$(RANLIB) $(UTILS_LIB)
	
utils_class.o: utils_class.cpp utils_class.h
	$(GPP) -c utils_class.cpp

$(ABEND_OBJS):
		cd $(ABEND_DIR); make clean; make; cd ..

$(QUEUE_MGR_OBJS):
		cd $(QUEUE_MGR_DIR); make clean; make; cd ..

$(THREAD_MGR_OBJS):
		cd $(THREAD_MGR_DIR); make clean; make; cd ..

clean: 
	$(RM) $(UTILS_LIB); $(RM) $(UTILS_OBJS)

