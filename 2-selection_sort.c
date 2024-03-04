#include "sort.h"

/**
 * swap - swaps elements
 * a: temp int
 * b: temp int
 * Return: void
 */

void swap(int *a, int *b)
{
        int temp = *a;

        *a = *b;
        *b = temp;
}

/**
 * print_array 
 * array: int
 * size: size_t
 * Return: void
 */
void print_array(int *array, size_t size)
{
        size_t i

        for (i = 0; i < size; i++)
{
        if (i > 0)
{
        putchar(' ');
}
printf("%d", array[i]);
}
putchar('\n');
}

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: int
 * @size: number of elements
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
        size_t n, m, o;

        for (n = 0; n < size - 1; n++)
        {
                size_t min_index = n;

                for (m = n; m < size; m++)
                {
                        if (array[m] < array[min_index])
                        {
                                min_index = m;
                        }
                }
                if (min_index != n)
                {
                        swap(&array[n], &array[min_index]);
                        print_array(array, size);
                }
        }
}
