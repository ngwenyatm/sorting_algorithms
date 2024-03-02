#include "sort.h"
/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: Array of integers to be sorted.
 * @size: Size of array.
 *
 * Description: Prints current array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j, temp;
    bool swap = false;

    if (size < 2)
	    return;
  for (i = 0; i < size-1; i++)
  {
    for (j = 0; j < size-i-1; j++)
    {   if(array[j] > array[j + 1])
        {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
        swap = true;
	print_array(array, size);
        }
        if (swap == false) {
            break;
    }
  }
  }
}
