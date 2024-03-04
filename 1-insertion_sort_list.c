#include "sort.h"
/**
 * insertion_sort_list - Sorts DLL of integers with insertion sort
 * @list: A pointer to head of DLL
 *
 * Description: Print dll  after each time swapped.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current;

	if (*list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			current = current->prev;
		}
		temp = current->next;
		current->next = current->prev;
		if (current->prev)
		{
			current->prev->next = current;
		}
		else
		{
			*list = current;
		}
		current = temp;
	}
	print_list(current);
	printf("\n");
}
