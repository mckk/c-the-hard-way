#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct List {
  int count;
  ListNode *first;
  ListNode *last;
} List;

List *List_create();
void List_destroy(List *list);
void List_clear(List *list);
void List_clear_destroy(List *list);

/*
 * Returns a pointer to a shallow copy of list.
 * The values are not copied, but the internal structure is.
 */
List *List_shallow_copy(List *list);

void List_push(List *list, void *value);
void *List_pop(List *list);

void List_unshift(List *list, void *value);
void *List_shift(List *list);

void *List_remove(List *list, ListNode *node);

static inline int List_count(List *list)
{
  return list->count;
}

static inline void *List_first(List *list)
{
  return list->first ? list->first->value : NULL;
}

static inline void *List_last(List *list)
{
  return list->last ? list->last->value : NULL;
}

#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                  ListNode *V = NULL;\
                  for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
