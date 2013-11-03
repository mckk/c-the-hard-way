#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void die(const char *message)
{
  if (errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }

  exit(1);
}

// comparator
typedef int (*compare_cb)(int a, int b);
// sorting function
typedef int *(sort_cb)(int *nums, int count, compare_cb cmp);


/**
 * A classic bubble sort function that uses the
 * compare_cb to do the sorting.
 */
int *bubble_sort(int *numbers, int count, compare_cb cmp)
{
  int temp = 0;
  int i = 0;
  int j = 0;
  int *target = malloc(count * sizeof(int));

  if (!target) die("Memory error.");

  memcpy(target, numbers, count * sizeof(int));

  for (i=0; i < count; i++) {
    for (j = 0; j < count - 1; j++) {
      if (cmp(target[j], target[j+1]) > 0) {
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      }
    }
  }
  
  return target;
}
int partition(int *numbers, int left, int right, int pivotIndex, compare_cb cmp)
{
  int tmp = 0; //swapper

  int pivotVal = numbers[pivotIndex];
  
  //move pivot to end
  tmp = numbers[right];
  numbers[right] = numbers[pivotIndex];
  numbers[pivotIndex] = tmp;

  int storeIndex = left; //forall i < storeIndex num[storeIndex] < pivotVal

  int i = 0;
  for (i = left; i < right; i++) {
    if (cmp(numbers[i], pivotVal) < 0) {
      tmp = numbers[storeIndex];
      numbers[storeIndex] = numbers[i];
      numbers[i] = tmp;
      storeIndex += 1;
    }
  }

  //put pivotval to its right place
  tmp = numbers[storeIndex];
  numbers[storeIndex] = numbers[right];
  numbers[right] = tmp;

  return storeIndex;
}

void qsort_helper(int *numbers, int left, int right, compare_cb cmp)
{
  if (left < right) {
    int pivotIndex = left;
    int newPivotIndex = partition(numbers, left, right, pivotIndex, cmp);
    qsort_helper(numbers, left, newPivotIndex - 1, cmp);
    qsort_helper(numbers, newPivotIndex + 1, right, cmp);
  }
}

int *quicksort(int *numbers, int count, compare_cb cmp)
{
  int *target = malloc(count * sizeof(int));
  qsort_helper(target, 0, count - 1, cmp);
  return target;
}

//Next two functions get underflow errors
//MIN_INT - MAX_INT!
int sorted_order(int a, int b)
{
  return a - b;
}

int reverse_order(int a, int b)
{
  return b - a;
}

int strange_order(int a, int b)
{
  if (a == 0 || b == 0) {
    return 0;
  } else {
    return a % b;
  }
}

/**
 * Used to test that we are sorting things correctly
 * by doing the sort and printing it out.
 */
void test_sorting(int *numbers, int count, compare_cb cmp, sort_cb sorter)
{
  int *sorted = sorter(numbers, count, cmp); 
  if (!sorted) die("Failed to sort as requested.");

  int i = 0;
  for (i = 0; i < count; i++) {
    printf("%d ", sorted[i]);
  }
  printf("\n");

  free(sorted);


  /*unsigned char *data = (unsigned char *)cmp;

  for (i = 0; i < 25; i++) {
    printf("%02x:", data[i]);
  }

  printf("\n");*/
}

int main(int argc, char *argv[])
{
  if (argc < 2) die("USAGE: ex18 4 3 1 5 8 2 3");

  int count = argc - 1;
  int i = 0;
  char **inputs = argv + 1;

  int *numbers = malloc(count * sizeof(int));
  if (!numbers) die("Memory error.");

  for (i = 0; i < count; i++) {
    numbers[i] = atoi(inputs[i]);
  }

  //Bubblesort
  printf("Bubble sort\n");
  test_sorting(numbers, count, sorted_order, bubble_sort);
  test_sorting(numbers, count, reverse_order, bubble_sort);
  test_sorting(numbers, count, strange_order, bubble_sort);
  printf("\n");

  //Quicksort
  printf("Quicksort:\n");
  test_sorting(numbers, count, sorted_order, quicksort);
  test_sorting(numbers, count, reverse_order, quicksort);
  test_sorting(numbers, count, strange_order, quicksort);
  
  free(numbers);

  return 0;
}
