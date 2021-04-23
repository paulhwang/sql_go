##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

OBJS = root_class.o raw_api_class.o

all: $(OBJS)
	$(GPP) -c $(OBJS)

root_class.o:	root_class.cpp root_class.h
	$(GPP) -c root_class.cpp

raw_api_class.o:	raw_api_class.cpp raw_api_class.h
	$(GPP) -c raw_api_class.cpp

clear: 
	rm *.o

