#include <assert.h>

#include <lcthw/list_algos.h>
#include <lcthw/dbg.h>


static inline void List_swap(ListNode *a, ListNode *b)
{
  void *tmp = a->value;
  a->value = b->value;
  b->value = tmp;
}

int List_bubble_sort(List *list, List_compare cmp)
{
  assert(list);
  assert(cmp);

  int swapped = 0;
  do {
    swapped = 0;
    LIST_FOREACH(list, first, next, cur) {
      if(cur->prev && cmp(cur->prev->value, cur->value) > 0) {
        List_swap(cur, cur->prev);
        swapped = 1;
      }
    }
  } while(swapped);

  return 0;
}

static List *List_merge(List *left, List *right, List_compare cmp)
{
  List *result = List_create();

  while(List_count(left) > 0 || List_count(right) > 0) {
    void *smallest_value = NULL;
    if(List_count(left) > 0 && List_count(right) > 0) {
      if(cmp(List_first(left), List_first(right)) <= 0) {
        smallest_value = List_shift(left);
      } else {
        smallest_value = List_shift(right);
      }
    } else if(List_count(left) > 0) {
      smallest_value = List_shift(left);
    } else {
      smallest_value = List_shift(right);
    }
    List_push(result, smallest_value);
  }

  return result;
}

List *List_merge_sort(List *list, List_compare cmp)
{
  if(List_count(list) <= 1) {
    return List_shallow_copy(list);
  }

  List *left = List_create();
  List *right = List_create();

  int middle = List_count(list)/2;
  LIST_FOREACH(list, first, next, cur) {
    if (middle > 0) {
      List_push(left, cur->value);
    } else {
      List_push(right, cur->value);
    }
    middle -= 1;
  }

  List *sorted_left = List_merge_sort(left, cmp);
  List_destroy(left);

  List *sorted_right = List_merge_sort(right, cmp);
  List_destroy(right);
  
  List *ret = List_merge(sorted_left, sorted_right, cmp);
  List_destroy(sorted_left);
  List_destroy(sorted_right);

  return ret;
}
