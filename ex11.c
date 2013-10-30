#include <stdio.h>

int main(int argc, char *argv[])
{
  //Print command line arguments in reverse order
  int i = argc - 1;
  while (i > 0) {
    printf("arg %d: %s\n", i, argv[i]);
    i--;
  }

  char *states[] = {
    "California", "Oregon",
    "washington", "Texas"
  };
  int num_states = 4;
 
  //Replace as many states as possible with command line arguments
  i = 0;
  while (i < num_states && i + 1 < argc) {
    states[i] = argv[i+1];
    i++;
  }
 
  //Print states
  i = 0;
  while (i < num_states) {
    printf("state %d: %s\n", i, states[i]);
    i++;
  }

  return 0;
}
