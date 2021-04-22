##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

SERVER = sqlgo

CORE_OBJS = core/root_class.o core/raw_api_class.o
SQLITE_OBJS = sqlite/sqlite3.o
TEST_OBJS = test/test_class.o

OBJS = main.o $(CORE_OBJS) $(SQLITE_OBJS) $(TEST_OBJS)

all:	$(SERVER)

$(SERVER): $(OBJS)
		$(GPP) $(OBJS) -o $(SERVER) -lpthread -ldl

clear: 
	rm $(SERVER); rm *.o

