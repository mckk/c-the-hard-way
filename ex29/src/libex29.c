#include <ctype.h>
#include <stdio.h>

#include "dbg.h"

int print_a_message(const char *msg, __attribute__((unused)) size_t size)
{
  printf("A STRING: %s\n", msg);
  return 0;
}

int uppercase(const char *msg, size_t size)
{
  size_t i = 0;

  for(i = 0; i < size-1 && msg[i] != '\0'; i++) {
    printf("%c", toupper(msg[i]));
  }

  printf("\n");
  return 0;
}

int lowercase(const char *msg, size_t size)
{
  size_t i = 0;

  for(i = 0; i < size-1 && msg[i] != '\0'; i++) {
    printf("%c", tolower(msg[i]));
  }

  printf("\n");
  return 0;
}

int fail_on_purpose(__attribute__((unused)) const char *msg, __attribute__((unused)) size_t size)
{
  return 1;
}
