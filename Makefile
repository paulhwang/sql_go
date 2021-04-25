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

UTILS_DIR = utils
UTILS_LIB = utils.a

ALL_LIBS = $(CORE_LIB) $(TEST_LIB) $(UTILS_LIB)
ALL_OBJS = main.o $(ALL_LIBS) 

clean_make:
	make clear; make all; ./$(SERVER)

all:	$(SERVER)

$(SERVER): $(ALL_OBJS) $(SQLITE_OBJS)
		$(GPP) $(ALL_OBJS) $(SQLITE_OBJS) -o $(SERVER) -lpthread -ldl

$(CORE_LIB):	
		cd $(CORE_DIR); make clear; make; cd ..

$(TEST_LIB):	
		cd $(TEST_DIR); make clear; make; cd ..

$(UTILS_LIB):	
		cd $(UTILS_DIR); make clear; make; cd ..

clear: 
	$(RM) $(SERVER); $(RM) $(ALL_OBJS)

