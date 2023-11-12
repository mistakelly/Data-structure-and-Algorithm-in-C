#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

/*define function to insert at the end of the list*/

void	insert_end(int data, struct Node **head)
{
	struct Node	*new_node;
	struct Node	*temp;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		printf("oh sorry! memmory allocation failed!\n");
		perror("malloc");
		free(new_node);
		// exit(1);
	}
	new_node->data = data;
	new_node->next = NULL;
	/*check if head is == NULL then set head to point to new node*/
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

/*define a function to print*/

void	display(struct Node *head)
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

/*function to free Nodes*/
void	free_list(struct Node *head)
{
	struct Node	*temp;

	temp = head;
	while (head != NULL)
	{
		head = temp->next;
		free(temp);
		temp = head;
	}
}
/*Driver code*/

int	main(void)
{
	struct Node	*head;

	head = NULL;
	int i, no_elem, elem;
	printf("How many elements you want to link? ");
	scanf("%d", &no_elem);
	for (i = 0; i < no_elem; i++)
	{
		/* code */
		printf("Enter Element [%d] ", i + 1);
		scanf("%d", &elem);
		insert_end(elem, &head);
		display(head);
	}
	/*free the allocated Nodes Memory*/
	free_list(head);
}
