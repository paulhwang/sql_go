##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

OBJS = test_class.o

all: $(OBJS)
	$(GPP) -c $(OBJS)

test_class.o:	test_class.cpp test_class.h
	$(GPP) -c test_class.cpp

clear: 
	rm *.o

