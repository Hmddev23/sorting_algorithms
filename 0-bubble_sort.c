#include "sort.h"

/**
  * swap_numbers - swap two numbers in an array.
  *
  * @a: First number to swap.
  * @b: Second number to swap.
  *
  * Return: Nothing.
  */

void swap_numbers(int *a, int *b)
{
	int tmp_nbr;

	tmp_nbr = *a;
	*a = *b;
	*b = tmp_nbr;
}

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
	size_t i, length = size;
	bool state = false;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (state == false)
	{
		state = true;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_numbers(array + i, array + i + 1);
				print_array(array, size);
				state = false;
			}
		}
		length--;
	}
}
