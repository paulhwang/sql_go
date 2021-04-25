##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

SERVER = sqlgo

MAIN_DIR = main
MAIN_OBJS = $(MAIN_DIR)/main.o

SQLITE_DIR = sqlite
SQLITE_OBJS = $(SQLITE_DIR)/sqlite3.o

CORE_DIR = core
CORE_LIB = core.a

TEST_DIR = test
TEST_LIB = test.a

UTILS_DIR = utils
UTILS_LIB = utils.a

MY_LIBS_OBJS = $(MAIN_OBJS) $(CORE_LIB) $(TEST_LIB) $(UTILS_LIB) 
IMPORT_LIBS_OBJS = $(SQLITE_OBJS) 
ALL_LIBS_OBJS = $(MY_LIBS_OBJS) $(IMPORT_LIBS_OBJS)

clean_make:
	make clean; make all; ./$(SERVER)

all:	$(SERVER)

$(SERVER): $(ALL_LIBS_OBJS)
		$(GPP) $(ALL_LIBS_OBJS) -o $(SERVER) -lpthread -ldl

$(MAIN_OBJS):	
		cd $(MAIN_DIR); make clean; make; cd ..

$(CORE_LIB):	
		cd $(CORE_DIR); make clean; make; cd ..

$(TEST_LIB):	
		cd $(TEST_DIR); make clean; make; cd ..

$(UTILS_LIB):	
		cd $(UTILS_DIR); make clean; make; cd ..

clean: 
	$(RM) $(SERVER); $(RM) $(MY_LIBS_OBJS)

