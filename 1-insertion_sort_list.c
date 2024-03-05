#include "sort.h"

/**
 * swap_it - Swaps nodes in a dll.
 * @head: Pointer to the DLL head
 * @node_1: first node to be swapped.
 * @node_2: The second node to be swapped.
 */
void swap_it(listint_t **head, listint_t **node_1, listint_t *node_2) {

  listint_t *temp_next = node_2->next;

  (*node_1)->next = temp_next;
  if (temp_next != NULL) {
    temp_next->prev = *node_1;
  }
  node_2->prev = (*node_1)->prev;
  node_2->next = *node_1;

  if ((*node_1)->prev != NULL) {
    (*node_1)->prev->next = node_2;
  } else {
    *head = node_2;
  }
 
  (*node_1)->prev = node_2;
  *node_1 = node_2->prev;
}

/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped
 */
void insertion_sort_list(listint_t **list) {
  listint_t *current, *previous, *next;

  if (list == NULL || *list == NULL || (*list)->next == NULL) {
    return;
  }

  for (current = (*list)->next; current != NULL; current = next) {
    next = current->next;
    previous = current->prev;

    while (previous != NULL && current->n < previous->n)
    {
      swap_it(list, &previous, current);
      print_list(*list);
    }
  }
}
