#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

void	insert_end(int data, struct Node **head)
{
	struct Node	*temp;
	struct Node	*element;

	element = (struct Node *)malloc(sizeof(struct Node));
	element->data = data;
	element->next = NULL;
	temp = *head;
	/**condition to set the temp -> next to the next node*/
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = element;
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
	int			arr[] = {20,40};
	int			size;

	size = sizeof(arr) / sizeof(arr[0]);
	array_to_linked_list(&head, arr, size);
	display(head);
	insert_end(60, &head);
	insert_end(80, &head);
	insert_end(100, &head);
	display(head);
}
