#include <stdio.h>
#include <stdlib.h>

/*define struct*/
struct			Node
{
	int			data;
	struct Node	*next;
};
/**function to insert at the end of the list*/
void	insert_end(int elem, struct Node **head)
/*pass the header pointer by reference*/
{
	struct Node *temp;
	struct Node *new_node;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	new_node->data = elem; /**set the new_node to data*/
	if (*head == NULL)
	{
		*head = new_node; /*point head to new_node*/
	}
	else
	{
		temp = *head; /*point temp to head*/
		while (temp->next != NULL)
		{
			/* code */
			temp = temp->next; /*move temp to next node*/
		}
		temp->next = new_node; /*link the new node to the end of the list*/
	}
}

void	print(struct Node *head)
{
	struct Node	*temp;

	temp = head;
	printf("Head ");
	while (temp != NULL)
	{
		printf("->[%d]", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	struct Node	*head;

	head = NULL;
	int i, no_elem, elem;
	printf("How many element you want to insert? ");
	scanf("%d", &no_elem);
	for (i = 0; i < no_elem; i++)
	{
		/* code */
		printf("Enter Element [%d]: ", i + 1);
		scanf("%d", &elem);
		/*function calls*/
		insert_end(elem, &head);
		print(head);
	}
	return (0);
}
