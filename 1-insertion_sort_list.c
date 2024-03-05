#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped
 */
void insertion_sort_list(listint_t **list)
{
   listint_t *sorted = NULL;
   listint_t *current, *next;

   while (*list != NULL)
   {
       current = *list;
       *list = current->next;

       if (sorted == NULL || sorted->n > current->n)
       {
           current->next = sorted;
           if (sorted != NULL)
           {
               sorted->prev = current;
           }
           sorted = current;
       }
       else
       {
           next = sorted;
           while (next->next != NULL && next->next->n <= current->n)
           {
               next = next->next;
           }
           current->next = next->next;
           if (next->next != NULL)
           {
               next->next->prev = current;
           }
           next->next = current;
           current->prev = next;
       }
       print_list((const listint_t *)*list);
   }

   *list = sorted;

}
