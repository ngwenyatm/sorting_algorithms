#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped.
 */
void insertion_sort_list(listint_t **list) {
    
    listint_t *sentinel = malloc(sizeof(listint_t));
    sentinel->next = *list;
    sentinel->prev = NULL;
    *list = sentinel;

    
    listint_t *current = sentinel->next;

    while (current) {
        
        while (current->prev && current->prev->n > current->n) {
            current = current->prev;
        }

      
        listint_t *temp = current->next;
        current->next = current->prev;
        if (current->prev) {
            current->prev->next = current;
        } else {
            
            *list = current;
        }
        current = temp;
    }

    
    *list = (*list)->next;
    free(sentinel);

  
    print_list(*list);
    printf("\n");
}
