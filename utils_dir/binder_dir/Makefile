##
#################################################################################
##                                       
##  Copyright (c) 2021 phwang. All rights reserved.
##
#################################################################################
##

include ../../Makefile.inc

BINDER_LIB = binder_lib.a
BINDER_OBJS = binder_class.o binder_bundle_class.o binder_port_class.o binder_port_mgr_class.o

clean_make:
	make clean; make all

all:	$(BINDER_LIB) $(BINDER_OBJS)

$(BINDER_LIB): $(BINDER_OBJS)
	$(AR) $(ARFLAGS) -r $(BINDER_LIB) $(BINDER_OBJS)
	$(RANLIB) $(BINDER_LIB)

binder_class.o:	binder_class.cpp binder_class.h
	$(GPP) -c binder_class.cpp

binder_bundle_class.o:	binder_bundle_class.cpp binder_bundle_class.h
	$(GPP) -c binder_bundle_class.cpp

binder_port_class.o:	binder_port_class.cpp binder_port_class.h
	$(GPP) -c binder_port_class.cpp

binder_port_mgr_class.o:	binder_port_mgr_class.cpp binder_port_mgr_class.h
	$(GPP) -c binder_port_mgr_class.cpp

clean: 
	$(RM) $(BINDER_LIB) $(BINDER_OBJS)


