#include "minunit.h"
#include <dlfcn.h>

typedef int(*lib_function)(const char *data, size_t size);
char *lib_file = "build/libex30.so";
void *lib = NULL;

int check_function(const char *func_to_run, const char *data, size_t size, int expected)
{
  lib_function func = dlsym(lib, func_to_run);
  check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

  int rc = func(data, size);
  check(rc == expected, "Function %s returned %d for data: %s", func_to_run, rc, data);

  return 1;
error:
  return 0;
}

char *test_dlopen()
{
  lib = dlopen(lib_file, RTLD_NOW);
  mu_assert(lib != NULL, "Failed to open the library to test.");
  return NULL;
}

char *test_functions()
{
  char data[] = "hello";
  size_t size = sizeof(data);

  mu_assert(check_function("print_a_message", data, size, 0), "print_a_message failed.");
  mu_assert(check_function("uppercase", data, size, 0), "uppercase failed.");
  mu_assert(check_function("lowercase", data, size, 0), "lowercase failed.");

  return NULL;
}

char *test_failures()
{
  mu_assert(check_function("fail_on_purpose", "Hello", 1, 1), "fail_on_purpose should fail.");

  return NULL;
}

char *test_dlclose()
{
  int rc = dlclose(lib);
  mu_assert(rc == 0, "Failed to close lib");
  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_dlopen);
  mu_run_test(test_functions);
  mu_run_test(test_failures);
  mu_run_test(test_dlclose);

  return NULL;
}

RUN_TESTS(all_tests);
