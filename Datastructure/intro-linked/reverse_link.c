#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Nodeptr; /*a typedef to change the name to what we want*/

struct		Node
{
	int		data;
	Nodeptr	next;
};

typedef struct Node Node;
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

void	reverse_list(struct Node **head)
{
	struct Node	*current;
	struct Node	*prev;
	struct Node	*next;

	current = *head;
	prev = NULL;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev; // Update the head to the new first node
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
	printf("Head-> ");
	while (node != NULL)
	{
		printf("<-[%d] ", node->data);
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
	// display(head);
	reverse_list(&head);
	display(head);
}
