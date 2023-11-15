/*
Write a function that adds a new node at the end of a list_t list.

Prototype: list_t *add_node_end(list_t **head, const char *str);
Return: the address of the new element, or NULL if it failed
str needs to be duplicated
You are allowed to use strdup
*/

#include "lists.h"

list_t	*add_node_end(list_t **head, const char *str)
{
	unsigned int	len;
	list_t			*element;
	list_t			*temp;

	len = 0;
	while (str[len])
		len++;
	/*create elemeent*/
	element = malloc(sizeof(list_t));
	if (element == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	element->str = strdup(str);
	if (element->str == NULL)
	{
		perror("malloc");
		free(element);
		return (NULL);
	}
	element->len = len;
	element->next = NULL;
    
    /*check if the head is empty*/
	if (*head == NULL)
	{
		(*head) = element;
	}
	else
	{
		temp = (*head);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = element;
	}
	return (element);
}
