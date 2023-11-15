#include "lists.h"

/*
Write a function that prints all the elements of a list_t list.

Prototype: size_t print_list(const list_t *h);
Return: the number of nodes
Format: see example
If str is NULL, print [0] (nil)
You are allowed to use printf
*/

size_t	print_list(const list_t *h)
{
	// const list_t *temp = h;

	size_t size = 0;

	while (h != NULL)
	{
		if (!h->str)
		{
			printf("[0] (nil)\n");
		}
		else
			printf("[%u] %s\n", h->len, h->str);

		h = h->next;
		size++;
	}

	return (size);
}
