#include "lists.h"

/*
Write a function that adds a new node at the beginning of a list_t list.

Prototype: list_t *add_node(list_t **head, const char *str);
Return: the address of the new element, or NULL if it failed
str needs to be duplicated
You are allowed to use strdup
*/

list_t	*add_node(list_t **head, const char *str)
{
	unsigned int	len;
	list_t			*element;

	len = 0;
	while (str[len])
		len++;
	/*create node*/
	element = malloc(sizeof(list_t));
	if (element == NULL)
	{
		printf("error\n");
		return (NULL);
	}
	element->str = strdup(str);
	if (element->str == NULL)
	{
		printf("error\n");
		free(element);
		return (NULL);
	}
	element->len = len;
	element->next = NULL;
	element->next = (*head);
	(*head) = element;
	return (element);
}
