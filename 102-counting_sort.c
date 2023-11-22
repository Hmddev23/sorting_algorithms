#include "sort.h"

/**
  * get_maximum - Get the biggest value in an array of integers.
  *
  * @array: Array of integers.
  * @size: Size of the array.
  *
  * Return: biggest number in the array.
  */

int get_maximum(int *array, int size)
{
	int maximum, i;

	for (maximum = array[0], i = 1; i < size; i++)
	{
		if (array[i] > maximum)
			maximum = array[i];
	}

	return (maximum);
}

/**
  * counting_sort - Sort an array using the counting sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, maximum, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maximum = get_maximum(array, size);
	counter = malloc(sizeof(int) * (maximum + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, maximum + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(counter);
}
