#include "sort.h"

/**
  * swap_ints - Swap two numbers in an array.
  *
  * @a: First value to swap.
  * @b: Second value to swap.
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
  * convert_tree - Turn a binary tree into a complete binary heap.
  *
  * @array: Array of numbers.
  * @size: Size of the array.
  * @base: Index.
  * @root: Root node of the binary tree.
  *
  * Return: Nothing.
  */

void convert_tree(int *array, size_t size, size_t base, size_t root)
{
	size_t l_node, r_node, bgt;

	l_node = 2 * root + 1;
	r_node = 2 * root + 2;
	bgt = root;

	if (l_node < base && array[l_node] > array[bgt])
		bgt = l_node;
	if (r_node < base && array[r_node] > array[bgt])
		bgt = r_node;

	if (bgt != root)
	{
		swap_ints(array + root, array + bgt);
		print_array(array, size);
		convert_tree(array, size, base, bgt);
	}
}

/**
  * heap_sort - Sort an array using the heap sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void heap_sort(int *array, size_t size)
{
	int index;

	if (array == NULL || size < 2)
		return;

	for (index = (size / 2) - 1; index >= 0; index--)
		convert_tree(array, size, size, index);

	for (index = size - 1; index > 0; index--)
	{
		swap_ints(array, array + index);
		print_array(array, size);
		convert_tree(array, size, index, 0);
	}
}
