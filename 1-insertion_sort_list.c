#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped
 */
void insertion_sort_list(listint_t **list) {
  listint_t *temp, *sorted = NULL;

  while (*list) {
    temp = *list;
    *list = temp->next;

    if (!sorted || sorted->prev->n <= temp->n) {
      temp->next = NULL;
      if (sorted) {
        sorted->prev->next = temp;
      } else {
        *list = temp;
      }
      temp->prev = sorted->prev;
      sorted = temp;
    } else {
      while (sorted && sorted->n < temp->n) {
        sorted = sorted->next;
      }

      temp->next = sorted;
      if (sorted) {
        sorted->prev->next = temp;
      }
      temp->prev = sorted->prev;
      if (!sorted) {
        *list = temp;
      }
      sorted->prev = temp;
    }
  }
  *list = sorted;
}
