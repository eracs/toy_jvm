#ifndef TOY_JVM_TEST_H
#define TOY_JVM_TEST_H

#include <iostream>
#include "../start/start_args.h"

void run_test(StartArgs *args);

void test_parse_start_args(StartArgs *args);

void test_search_zip_entry();

void test_search_file_entry();

void test_list_file(int argc, char *argv[]);

#endif