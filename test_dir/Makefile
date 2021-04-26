##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../Makefile.inc

TEST_LIB = test.a
TEST_OBJS = test_class.o

clean_make:
	make clean; make all

all: $(TEST_LIB)

$(TEST_LIB): $(TEST_OBJS)
	$(AR) $(ARFLAGS) -r $(TEST_LIB) $(TEST_OBJS)
	$(RANLIB) $(TEST_LIB)
	
test_class.o:	test_class.cpp test_class.h
	$(GPP) -c test_class.cpp

clean: 
	$(RM) $(TEST_LIB); $(RM) $(TEST_OBJS)

