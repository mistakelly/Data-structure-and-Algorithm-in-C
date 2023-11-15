#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

int	link_size(struct Node *head)
{
	int			size;
	struct Node	*temp;

	size = 0;
	temp = head;
	while (temp != NULL)
	{
		/* code */
		temp = temp->next;
		size++;
	}
	return (size);
}

void	insert_nth(int pos, struct Node **head)
{
	int			size;
	struct Node	*temp;
	struct Node	*element;
	struct Node	*previous;

	size = link_size(*head);
	/*check if position is greater than size or position less than zero*/
	if (pos > size || pos < 0)
	{
		printf("Invalid Position\n");
		// exit(0);
		return ;
	}
		temp = *head;
	if (pos == 0)
	{
		*head = temp->next;
		free(temp);
	}
	else
	{
		while (pos != 0)
		{
			previous = temp;
			temp = temp->next;
			pos--;
		}
		previous->next  = temp->next;
		free(temp);
	}
	// printf("size of the node [%d]", size);
	/**condition to set the temp -> next to the next node*/
}

void	array_to_linked_list(struct Node **head, int *arr, int size)
{
	int	i;

	struct Node *current, *element;
	if (size == 0)
	{
		*head = NULL;
		return ;
	}
	element = (struct Node *)malloc(sizeof(struct Node));
	element->data = arr[0];
	element->next = NULL;
	*head = element;
	i = 0;
	current = *head;
	for (i = 1; i < size; i++)
	{
		/* code */
		current->next = (struct Node *)malloc(sizeof(struct Node));
		current = current->next;
		current->data = arr[i];
		current->next = NULL;
	}
}

void	display(struct Node *node)
{
	// as linked list will end when Node is Null
	printf("Head ");
	while (node != NULL)
	{
		printf("-> [%d] ", node->data);
		node = node->next;
	}
	printf("\n");
}

int	main(void)
{
	struct Node	*head;
	int			arr[] = {20, 40, 5, 3, 4};
	int			size;

	size = sizeof(arr) / sizeof(arr[0]);
	array_to_linked_list(&head, arr, size);
	display(head);
	insert_nth(1, &head);
	insert_nth(3, &head);
	display(head);
}
