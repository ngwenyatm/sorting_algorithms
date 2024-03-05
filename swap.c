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
