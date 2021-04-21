##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

OBJS = main.o root_class.o sqlite/sqlite3.o

all: $(OBJS)
	$(CC) $(OBJS) -o go -lpthread -ldl

clear: 
	rm go; rm *.o

