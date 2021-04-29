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

SqlServerRootClass *sql_server_root_object;
TestClass *test;

int main() {
	printf("hello phwang\n");
	sql_server_root_object = new SqlServerRootClass;
	test = new TestClass(sql_server_root_object);
	
	test->doTest();

}
