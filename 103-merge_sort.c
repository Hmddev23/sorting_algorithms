#include "sort.h"

/**
  * merge_subarr - Sort a subarray of integers.
  *
  * @subarr: Subarray of integers to sort.
  * @buff: Buffer to store the sorted subarray.
  * @front: Front index of the array.
  * @mid: Middle index of the array.
  * @back: Back index of the array.
  *
  * Return: Nothing.
  */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
  * merge_sort_recursive - Implement the merge sort algorithm through recursion.
  *
  * @subarr: Subarray of integers to sort.
  * @buff: Buffer to store the sorted result.
  * @front: Front index of the subarray.
  * @back: Back index of the subarray.
  *
  * Return: Nothing.
  */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
  * merge_sort - Sort an array using the merge sort algorithm.
  *
  * @array: Array to sort.
  * @size: Size of the array.
  *
  * Return: Nothing.
  */

void merge_sort(int *array, size_t size)
{
	int *store;

	if (array == NULL || size < 2)
		return;

	store = malloc(sizeof(int) * size);
	if (store == NULL)
		return;

	merge_sort_recursive(array, store, 0, size);

	free(store);
}
