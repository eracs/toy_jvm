#ifndef TOY_JVM_TEST_H
#define TOY_JVM_TEST_H

#include <iostream>
void run_test(int argc, char *argv[]);

void test_parse_start_args(int argc, char *argv[]);

void test_search_zip_entry();

void test_search_file_entry();

void test_list_file(int argc, char *argv[]);

#endif