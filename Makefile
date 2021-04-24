##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

SERVER = sqlgo

SQLITE_DIR = sqlite
SQLITE_OBJS = $(SQLITE_DIR)/sqlite3.o

CORE_DIR = core
CORE_LIB = core.a

TEST_DIR = test
TEST_LIB = test.a

ALL_LIBS = $(CORE_LIB) $(TEST_LIB) 
ALL_OBJS = main.o $(ALL_LIBS) 


all:	$(SERVER)

$(SERVER): $(ALL_OBJS) $(SQLITE_OBJS)
		$(GPP) $(ALL_OBJS) $(SQLITE_OBJS) -o $(SERVER) -lpthread -ldl

$(CORE_LIB):	
		cd $(CORE_DIR); make; cd ..

$(TEST_LIB):	
		cd $(TEST_DIR); make; cd ..

clear: 
	$(RM) $(SERVER); $(RM) $(ALL_OBJS)

