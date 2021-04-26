##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

SQL_SERVER_LIB = sql_server_lib.a
SQL_SERVER_OBJS = root_class.o raw_api_class.o

clean_make:
	make clean; make all

all: $(SQL_SERVER_LIB)

$(SQL_SERVER_LIB): $(SQL_SERVER_OBJS)
	$(AR) $(ARFLAGS) -r $(SQL_SERVER_LIB) $(SQL_SERVER_OBJS)
	$(RANLIB) $(SQL_SERVER_LIB)

root_class.o:	root_class.cpp root_class.h
	$(GPP) -c root_class.cpp

raw_api_class.o:	raw_api_class.cpp raw_api_class.h
	$(GPP) -c raw_api_class.cpp

clean: 
	$(RM) $(SQL_SERVER_LIB); $(RM) $(SQL_SERVER_OBJS)

