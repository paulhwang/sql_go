##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

TARGET_DIR = target
SQL_SERVER = $(TARGET_DIR)/sqlgo

MAIN_DIR = main
MAIN_OBJS = $(MAIN_DIR)/main.o

CORE_DIR = core
CORE_LIB = $(CORE_DIR)/core.a

TEST_DIR = test
TEST_LIB = $(TEST_DIR)/test.a

UTILS_DIR = utils
UTILS_LIB = $(UTILS_DIR)/utils_lib.a

SQLITE_DIR = sqlite
SQLITE_OBJS = $(SQLITE_DIR)/sqlite3.o

MY_LIBS_OBJS = $(MAIN_OBJS) $(CORE_LIB) $(TEST_LIB) $(UTILS_LIB) 
IMPORT_LIBS_OBJS = $(SQLITE_OBJS) 
ALL_LIBS_OBJS = $(MY_LIBS_OBJS) $(IMPORT_LIBS_OBJS)

clean_make:
	make clean; make all; ./$(SQL_SERVER)

all:	$(SQL_SERVER)

$(SQL_SERVER): $(ALL_LIBS_OBJS)
		$(GPP) $(ALL_LIBS_OBJS) -o $(SQL_SERVER) -lpthread -ldl

$(MAIN_OBJS):	
		cd $(MAIN_DIR); make clean; make; cd ..

$(TEST_LIB):	
		cd $(TEST_DIR); make clean; make; cd ..

$(CORE_LIB):	
		cd $(CORE_DIR); make clean; make; cd ..

$(UTILS_LIB):	
		cd $(UTILS_DIR); make clean; make; cd ..

clean: 
	$(RM) $(SQL_SERVER); $(RM) $(MY_LIBS_OBJS)

