#include "sort.h"

/**
  * devide_fct - Find the pivot element in the array.
  *
  * @array: Array to sort.
  * @start: Start index of the subarray.
  * @end: End index of the subarray.
  * @size: Size of the array.
  *
  * Return: Index of the pivot element.
  */

int devide_fct(int *array, int start, int end, size_t size)
{
	int j, tmp_val, i;

	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] < array[end])
		{
			i++;
			tmp_val = array[i];
			array[i] = array[j];
			array[j] = tmp_val;
			if (j != i)
				print_array(array, size);
		}
	}

	i++;
	if (array[i] != array[end])
	{
		tmp_val = array[end];
		array[end] = array[i];
		array[i] = tmp_val;
		print_array(array, size);
	}
	return (i);
}

/**
  * quick_sort_recursion - Sort the array with recursion.
  *
  * @array: Array to sort.
  * @start: Start index of the subarray.
  * @end: End index of the subarray.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void quick_sort_recursion(int *array, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = devide_fct(array, start, end, size);
	quick_sort_recursion(array, start, pivot - 1, size);
	quick_sort_recursion(array, pivot + 1, end, size);
}

/**
  * quick_sort - Sort the array using quick sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
