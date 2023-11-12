#include <stdio.h>
#include <stdlib.h>

/*Define a struct*/

struct			Node
{
	int			data;
	struct Node	*next;
};

/**
 * @brief - function to insert node at nth index
 * insert_Node - it inserts node at any given position provided
 *  its a valid position.
 * @param1 - struct Node **head - pointer to pointer to head Node;
 * @param2 - int data - data to be inserted;
 *
 * @return
	- function does not return any value cause we using pointer to modify the head in the main function.
 */
/*function to get the sizeof the List*/

/*function to insert element at the end of the list*/
struct Node	*insert_end(struct Node *head, int data)
{
	struct Node	*new_node;
	struct Node	*temp;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		printf("oh no memory allocation failed!");
		exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (head);
}

int	getListSize(struct Node *head)
{
	int	size;

	size = 0;
	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

void	insert_nth(int pos, int data, struct Node **head)
{
	int			size;
	struct Node	*new_node;
	struct Node	*temp;

	size = getListSize(*head);
	new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = data;
	if (pos > size || pos < 0)
	{
		printf("Invalid Position\n");
		free(new_node);
		exit(1);
	}
	if (pos == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (pos != 1)
		{
			temp = temp->next;
			pos--;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

/**function to insert element at nth index*/

/**printing the nodes*/

void	print_nodes(struct Node *head)
{
	struct Node	*temp;

	temp = head;
	printf("Head ");
	while (temp != NULL)
	{
		printf("->[%d] ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void	free_list(struct Node *head)
{
	struct Node	*temp;
	struct Node	*next;

	temp = head;
	while (temp != NULL)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
}

int	main(void)
{
	struct Node	*head;
	int			count;

	head = NULL;
	count = 0;
	int i, no_elem, elem, pos;
	printf("how many elements you want to link? ");
	scanf("%d", &no_elem);
	for (i = 0; i < no_elem; i++)
	{
		/* code */
		printf("Enter Element [%d]: ", i + 1);
		scanf("%d", &elem);
		head = insert_end(head, elem);
		print_nodes(head);
		count++;
		if (count == no_elem)
		{
			no_elem = 0;
			printf("How many element you wanna insert at index: ");
			scanf("%d", &no_elem);
			for (i = 0; i < no_elem; i++)
			{
				/* code */
				printf("Enter element [%d]: ", i + 1);
				scanf("%d", &elem);
				printf("Enter the index [%d]: ", i + 1);
				scanf("%d", &pos);
				insert_nth(pos, elem, &head);
				print_nodes(head);
				printf("%d\n", count);
			}
		}
	}

    free_list(head);
	return (0);
}

