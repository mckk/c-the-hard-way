#include <lcthw/list.h>
#include <lcthw/dbg.h>

#include <assert.h>

int check_invariant(List *list)
{
  assert(list);

  if (list->count < 0) {
    return 0;
  } else if (list->count == 0) {
    return list->first == NULL && list->last == NULL;
  } else {
    return list->first != NULL && list->last != NULL;
  }
}

List *List_create()
{
  return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  LIST_FOREACH(list, first, next, cur) {
    if(cur->prev) {
      free(cur->prev);
    }
  }
  free(list->last);
  free(list);
}

void List_clear(List *list)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  LIST_FOREACH(list, first, next, cur) {
    free(cur->value);
  }
}

void List_clear_destroy(List *list)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  LIST_FOREACH(list, first, next, cur) {
    free(cur->value);
    if(cur->prev) {
      free(cur->prev);
    }
  }
  free(list->last);
  free(list);
}

void List_push(List *list, void *value)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if(list->last == NULL) {
    list->first = node;
    list->last = node;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count += 1;

error:
  assert(check_invariant(list) && "List invariant has to be valid on exit");
  return;
}

void *List_pop(List *list)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  ListNode *node = list->last;
  void *ret = node != NULL ? List_remove(list, node) : NULL;
  
  assert(check_invariant(list) && "List invariant has to be valid on exit");

  return ret;
}

void List_unshift(List *list, void *value)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if(list->first == NULL) {
    list->first = node;
    list->last = node;
  } else {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }

  list->count += 1;
  
error:
  assert(check_invariant(list) && "List invariant has to be valid on exit");
  return;
}

void *List_shift(List *list)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  ListNode *node = list->first;
  void *ret = node != NULL ? List_remove(list, node) : NULL;

  assert(check_invariant(list) && "List invariant has to be valid on exit");

  return ret;
}

void *List_remove(List *list, ListNode *node)
{
  assert(list);
  assert(check_invariant(list) && "List invariant has to be valid on entry");

  void *result = NULL;
  
  check(list->first && list->last, "List is empty.");
  check(node, "node can't be NULL.");

  if(node == list->first && node == list->last) {
    list->first = NULL;
    list->last = NULL;
  } else if(node == list->first) {
    list->first = list->first->next;
    check(list->first, "Invalid list. Somehow got a first that is NULL.");
    list->first->prev = NULL;
  } else if(node == list->last) {
    list->last = list->last->prev;
    check(list->last, "Invalid list. Somehow got a last that is NULL.");
    list->last->next = NULL;
  } else {
    ListNode *after = node->next;
    ListNode *before = node->prev;
    before->next = after;
    after->prev = before;
  }

  list->count -= 1;
  result = node->value;
  free(node);

error:
  assert(check_invariant(list) && "List invariant has to be valid on exit");
  return result;
}
