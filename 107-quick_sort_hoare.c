#include "sort.h"

/**
  * swap_nmbrs - Swap two numbers in an array.
  *
  * @a: First number to swap.
  * @b: Second number to swap.
  *
  * Return: Nothing.
  */

void swap_nmbrs(int *a, int *b)
{
	int tmp_val;

	tmp_val = *a;
	*a = *b;
	*b = tmp_val;
}

/**
  * hoare_partition - Order a sub-array to the hoare partition scheme.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  * @left: Starting index of the sub-array.
  * @right: Ending index of the sub-array.
  *
  * Return: Partition index.
  */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, up, down;

	pivot = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_ints(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
  * hoare_sort - Sort the array using the quicksort algorithm with recursion.
  *
  * @array: Array of numbers to sort.
  * @size: Size of the array.
  * @left: Starting index of the array.
  * @right: Ending index of the array.
  *
  * Return: Nothing.
  */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partition - 1);
		hoare_sort(array, size, partition, right);
	}
}

/**
  * quick_sort_hoare - Sort an array using the quicksort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
