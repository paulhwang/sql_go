##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include Makefile.inc

TARGET_DIR = target_dir
SQL_SERVER = $(TARGET_DIR)/sql_server

MAIN_DIR = main_dir
MAIN_OBJS = $(MAIN_DIR)/main.o

SQL_SERVER_DIR = sql_server_dir
SQL_SERVER_LIB = $(SQL_SERVER_DIR)/sql_server_lib.a

TEST_DIR = test_dir
TEST_LIB = $(TEST_DIR)/test.a

UTILS_DIR = utils_dir
UTILS_LIB = $(UTILS_DIR)/utils_lib.a

SQLITE_DIR = sqlite_dir
SQLITE_OBJS = $(SQLITE_DIR)/sqlite3.o

MY_LIBS_OBJS = $(MAIN_OBJS) $(SQL_SERVER_LIB) $(TEST_LIB) $(UTILS_LIB) 
IMPORT_LIBS_OBJS = $(SQLITE_OBJS) 
ALL_LIBS_OBJS = $(MY_LIBS_OBJS) $(IMPORT_LIBS_OBJS)

clean_make:
	make clean; make all

all:	$(SQL_SERVER)

$(SQL_SERVER): $(ALL_LIBS_OBJS)
		$(GPP) $(ALL_LIBS_OBJS) -o $(SQL_SERVER) -lpthread -ldl

$(MAIN_OBJS):	
		cd $(MAIN_DIR); make clean; make; cd ..

$(TEST_LIB):	
		cd $(TEST_DIR); make clean; make; cd ..

$(SQL_SERVER_LIB):	
		cd $(SQL_SERVER_DIR); make clean; make; cd ..

$(UTILS_LIB):	
		cd $(UTILS_DIR); make clean; make; cd ..

clean: 
	$(RM) $(SQL_SERVER); $(RM) $(MY_LIBS_OBJS)

