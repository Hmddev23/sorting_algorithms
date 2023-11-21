#include "sort.h"

/**
  * selection_sort - Sort an array using the selection sort algorithm.
  *
  * @array: Pointer to the array.
  * @size: Array length.
  *
  * Return: Nothing.
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_val, tmp_val;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_val = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_val] > array[j])
				min_val = j;
		}
		if (min_val != i)
		{
			tmp_val = array[i];
			array[i] = array[min_val];
			array[min_val] = tmp_val;
			print_array(array, size);
		}
	}
}
