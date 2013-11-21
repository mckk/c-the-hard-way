#include <dlfcn.h>
#include <stdio.h>

#include "dbg.h"

#define MAX_LEN 1024

typedef int (*lib_function)(const char *data, size_t size);

int call_function(void *lib, char *func_name, char *data, size_t size)
{
  lib_function func = dlsym(lib, func_name);
  check(func != NULL, "Did not find %s function in the library: %s", func_name, dlerror());

  int rc = func(data, size);
  check(rc == 0, "Function %s returned %d for data: %s", func_name, rc, data);

  return 0;

error:
  return -1;
}

int main(int argc, char *argv[])
{
  check(argc == 2, "Pass the library name");
  char *lib_file = argv[1];

  char test_data[] = "Hello World";
  size_t size = sizeof(test_data);

  void *lib = dlopen(lib_file, RTLD_NOW);
  check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());
  
  char *func_names[] = {"print_a_message", "uppercase", "lowercase"};
  int i = 0;
  for(i = 0; i < 3; i++) {
    int rc = 0;
    rc = call_function(lib, func_names[i], test_data, size);
    check(rc == 0, "Call to %s failed", func_names[i]);
  }

  int rc = 0;
  rc = call_function(lib, "fail_on_purpose", test_data, size);
  check(rc != 0, "Call to fail_on_purpose succeeded");

  rc = dlclose(lib);
  check(rc == 0, "Failed to close library %s", lib_file);
  return 0;

error:
  return 1;
}

