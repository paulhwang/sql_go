/*
 ******************************************************************************
 *                                       
 *  Copyright (c) 2021 phwang. All rights reserved.
 *
 ******************************************************************************
 */

#include <stdio.h>
#include "../sql_server_dir/sql_server_root_class.h"
#include "../test_dir/test_class.h"

SqlServerRootClass *root;
TestClass *test;

int main() {
	printf("hello phwang\n");
	root = new SqlServerRootClass;
	test = new TestClass(root);
	test->doTest();

}
