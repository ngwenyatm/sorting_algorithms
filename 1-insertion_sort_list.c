#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped.
 */
void insertion_sort_list(listint_t **list) {
    listint_t *temp, *sorted = NULL;


    while (*list) {
        temp = *list;
        *list = temp->next;

        while (sorted && sorted->n < temp->n) {
            sorted = sorted->next;
        }


        if (sorted) {
            temp->next = sorted;
            temp->prev = sorted->prev;
            sorted->prev->next = temp;
            sorted->prev = temp;
        } else {

            temp->next = sorted;
            temp->prev = NULL;
            sorted = temp;
        }

        print_list(*list);

    *list = sorted;
}
