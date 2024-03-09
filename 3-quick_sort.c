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
 * lomuto_partition - divides the array
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: array
 */
int lomuto_partition(int *array, int low, int high)
{
        int pivot = array[high];
        int a = low;
        int i;

        for (i = low; i < high; i++)
        {
                if (array[i] < pivot)
                {
                        a++;
                        swap(&array[a], &array[i]);
                }
        }
        swap(&array[a + 1], &array[high]);
 return (a + 1);
}
/**
 * lomjuto_sort - sorts the array
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: array
 */
void lomuto_sort(int *array, int low, int high)
{
        if (low < high)
        {
                int partition_ind = lomuto_partition(array, low, high);

                print_array(array, high - low + 1);
                lomuto_sort(array, low, partition_ind - 1);
                lomuto_sort(array, partition_ind + 1, high);
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
