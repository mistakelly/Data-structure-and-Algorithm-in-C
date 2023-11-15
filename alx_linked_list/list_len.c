// Write a function that returns the number of elements in a linked list_t list.

// Prototype: size_t list_len(const list_t *h);

#include "lists.h"

void	list_len(list_t **h, size_t *size)
{

    *size = 0;
	while (*h)
	{
		*h = (*h)->next;
		(*size)++;
	}
}
