#include "sort.h"

/**
  * get_maximum - Get the biggest value in an array of numbers.
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
  * @sig: Significant digit to sort on.
  * @buff: Buffer to store the sorted array.
  *
  * Return: Nothing.
  */

void counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
  * radix_sort - Sort an array using the radix sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void radix_sort(int *array, size_t size)
{
	int maximum, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maximum = get_maximum(array, size);
	for (sig = 1; maximum / sig > 0; sig *= 10)
	{
		counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
