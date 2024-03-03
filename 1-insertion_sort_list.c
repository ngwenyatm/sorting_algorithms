#include "sort.h"
void insertion_sort_list(listint_t **list) {
    listint_t *sorted = NULL;
    listint_t *temp;

    while (*list) {
        temp = *list;
        *list = (*list)->next;

        if (!sorted || sorted->n >= temp->n) {
            temp->next = sorted;
            temp->prev = NULL;
            if (sorted) {
                sorted->prev = temp;
            }
            sorted = temp;
        } else {
            listint_t *node = sorted;
            while (node && node->n < temp->n) {
                node = node->next;
            }

            temp->next = node;
            if (node) {
                node->prev = temp;
            }
            temp->prev = node->prev;
            if (temp->prev) {
                temp->prev->next = temp;
            } else {
                sorted = temp;
            }
        }
    }

    *list = sorted;
}
