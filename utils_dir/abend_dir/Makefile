##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

ABEND_OBJS = abend_class.o

clean_make:
	make clean; make all

all:	$(ABEND_OBJS)

abend_class.o:	abend_class.cpp abend_class.h
	$(GPP) -c abend_class.cpp

clean: 
	$(RM) $(ABEND_OBJS)


