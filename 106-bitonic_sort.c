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
  * bitonic_merge - Sort a bitonic sequence inside an array of numbers.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  * @start: Starting index.
  * @seq: Size of the sequence to sort.
  * @flow: Direction to sort in.
  *
  * Return: Nothing.
  */

void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
char flow)
{
	size_t idx, jmp = seq / 2;

	if (seq > 1)
	{
		for (idx = start; idx < start + jmp; idx++)
		{
			if ((flow == UP && array[idx] > array[idx + jmp]) ||
					(flow == DOWN && array[idx] < array[idx + jmp]))
				swap_nmbrs(array + idx, array + idx + jmp);
		}
		bitonic_merge(array, size, start, jmp, flow);
		bitonic_merge(array, size, start + jmp, jmp, flow);
	}
}

/**
  * bitonic_sequence - Convert an array of numbers into a bitonic sequence.
  *
  * @array: Array of integers.
  * @size: Size of the array.
  * @start: Starting index of the sequence.
  * @seq: Size of a sequence block.
  * @flow: Direction to sort the sequence block.
  *
  * Return: Nothing.
  */

void bitonic_sequence(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t cutter = seq / 2;
	char *strng = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, strng);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, cutter, UP);
		bitonic_sequence(array, size, start + cutter, cutter, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, strng);
		print_array(array + start, seq);
	}
}

/**
  * bitonic_sort - Sort an array using the bitonic sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
