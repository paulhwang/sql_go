/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../sql_server_dir/root_class.h"
#include "../test_dir/test_class.h"

RootClass *root;
TestClass *test;

int main() {
	printf("hello phwang\n");
	root = new RootClass;
	test = new TestClass(root);
	test->doTest();

}
