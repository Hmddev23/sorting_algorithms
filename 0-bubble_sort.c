#include "sort.h"

/**
  * bubble_sort - Sort an array of integers in ascending order.
  *
  * @array: Array of integers.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t tmp_val;

	if (size < 2 || !array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp_val = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp_val;
				print_array(array, size);
			}
		}
	}
}
