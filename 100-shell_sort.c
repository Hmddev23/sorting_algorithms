#include "sort.h"

/**
  * swap_ints - Swap two integers in an array.
  *
  * @a: First number to swap.
  * @b: Second number to swap.
  *
  * Return: Nothing.
  */

void swap_ints(int *a, int *b)
{
	int tmp_val;

	tmp_val = *a;
	*a = *b;
	*b = tmp_val;
}

/**
  * shell_sort - Sort an array using the shell sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void shell_sort(int *array, size_t size)
{
	size_t distance, i, j;

	if (array == NULL || size < 2)
		return;

	for (distance = 1; distance < (size / 3);)
		distance = distance * 3 + 1;

	for (; distance >= 1; distance /= 3)
	{
		for (i = distance; i < size; i++)
		{
			j = i;
			while (j >= distance && array[j - distance] > array[j])
			{
				swap_ints(array + j, array + (j - distance));
				j -= distance;
			}
		}
		print_array(array, size);
	}
}
