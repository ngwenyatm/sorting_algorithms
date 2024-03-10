#include "sort.h"
/**
 * swap - swaps ints
 * @a: int
 * @b: int
 * Return: void
 */
void swap(int *a, int *b)
{
        int temp = *a;

        *a = *b;
        *b = temp;
}
/**
 * partition - separates the array into highest and lowest order
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: sorted arrray
 */
int partition(int *array, int low, int high)
{
        int pivot = array[high];
        int a = low;
        int n;

        for (n = low; n <= high - 1; n++)
        {
                if (array[n] < pivot)
                {
                        a++;
                        swap(&array[a], &array[n]);
                }
        }
        swap(&array[a + 1], &array[high]);
        return (a + 1);
}

/**
 * sort_assist - sorts the array
 * @array: int
 * @low: pivot element
 * @high: pivot element
 * Return: void
 */
void sort_assist(int *array, int low, int high)
{
        if (low < high)
        {
                int i = partition(array, low, high);

                print_array(array, high - low + 1);
                sort_assist(array, low, i - 1);
                sort_assist(array, i + 1, high);
        }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: int
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
        sort_assist(array, 0, size - 1);
}
