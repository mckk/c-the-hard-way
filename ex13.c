#include <stdio.h>

int main(int argc, char *argv[])
{
  int j = 0;
  for (j = 1; j < argc; j++) {
    printf("Argument %d: %s\n", j, argv[j]);

    int i = 0;
    for (i = 0; argv[j][i] != '\0'; i++) {
      char letter = argv[j][i];

      switch(letter) {
        case 'a':
        case 'A':
          printf("%d: 'A'\n", i);
          break;

        case 'e':
        case 'E':
          printf("%d: 'E'\n", i);
          break;

        case 'i':
        case 'I':
          printf("%d: 'I'\n", i);
          break;

        case 'o':
        case 'O':
          printf("%d: 'O'\n", i);
          break;

        case 'u':
        case 'U':
          printf("%d: 'U'\n", i);
          break;

        case 'y':
        case 'Y':
          if (i > 2) {
            printf("%d: 'Y'\n", i);
          }
          break;

        default:
          printf("%d: %c is not a vowel\n", i, letter);
      }
    }

    printf("\n");
  }

  return 0;
}
