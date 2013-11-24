#ifndef _list_algos_h
#define _list_algos_h

#include <lcthw/list.h>

/*
 *  List_compare is a comparator function type. It should return:
 *  * Smaller than 0 if lhs is smaller than rhs
 *  * 0 if they are equal
 *  * Bigger than 0 if lhs is larger than rhs
 */
typedef int (*List_compare)(void *, void *);

int List_bubble_sort(List *list, List_compare compare_func);
List *List_merge_sort(List *list, List_compare compare_func);

#endif
