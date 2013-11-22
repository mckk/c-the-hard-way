#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <lcthw/dbg.h>
#include <stdio.h>
#include <stdlib.h>

#define mu_suite_start() char *message = NULL

#define mu_assert(test, message) if (!(test)) { log_err(message); return message; }
#define mu_run_test(test) do {debug("\n-----%s", " " #test); \
  message = test(); tests_run++; if (message) return message;} while(0)

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
  argc = 1;\
  printf("----\nRUNNING: %s\n", argv[0]);\
  char *result = name();\
  if (result != NULL) {\
    printf("FAILED: %s\n", result);\
  }\
  else {\
    printf("ALL TESTS PASSED\n");\
  }\
  printf("Tests run: %d\n", tests_run);\
  exit(result != 0);\
}

int tests_run = 0;

#endif
