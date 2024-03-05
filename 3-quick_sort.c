#include "sort.h"
/**
 * swap - swaps elements
 * @a: temp int
 * @b: temp int
 * Return: void
 */
void swap(int *a, int *b)
{
        int temp = *a;

        *a = *b;
        *b = temp;
}
/**
 * partition - divides the array
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: array
 */
int partition(int *array, int low, int high)
{
        int piv = array[high];
        int a = low - 1;
        int i;

        for (i = low; i < high; i++)
        {
                if (array[i] < piv)
                {
                        a++;
                        swap(&array[a], &array[i]);
                }
        }
        swap(&array[a + 1], &array[high]);
        return (a + 1);
}
/**
 * quick_sort_assit - sorts the array
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: array
 */
void quick_sort_assit(int *array, int low, int high)
{
        if (low < high)
        {
                int partition_ind = partition(array, low, high);

                print_array(array, high - low + 1);
                quick_sort_assit(array, low, partition_ind - 1);
                quick_sort_assit(array, partition_ind + 1, high);
        }
}
/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: int
 * @size: size_t
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
        quick_sort_assit(array, 0, size - 1);
}
