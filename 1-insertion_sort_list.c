#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped.
 */
void insertion_sort_list(listint_t **list) {
   listint_t *sorted = NULL, *curr, *next, *aux;

  for (curr = *list; curr; curr = next) {
       next = curr->next; 

       if (sorted == NULL || sorted->n >= curr->n) {
           curr->next = sorted;
           curr->prev = NULL;
           if (sorted) {
               sorted->prev = curr;
           }
           sorted = curr;
       } else {
           aux = sorted;
           while (aux->next && aux->next->n < curr->n) {
               aux = aux->next;
           }
           curr->next = aux->next;
           if (aux->next) {
               aux->next->prev = curr;
           }
           curr->prev = aux;
           aux->next = curr;
       }
       while (list) {
       printf("%d ", list->n);
       list = list->next;
   }
   printf("\n");
   }
   *list = sorted;
}
