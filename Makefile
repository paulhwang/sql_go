##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

OBJS = main.o root_class.o

all: $(OBJS)
	$(CC) $(OBJS) -o go

clear: 
	rm go; rm *.o

