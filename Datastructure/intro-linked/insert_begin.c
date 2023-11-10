#include <stdio.h>
#include <stdlib.h>

/*define struct*/
struct			Node
{
	/* data */
	int			data;
	struct Node	*next;
};

/*define function to insert*/

void	insert_begin(int elem, struct Node **head)
{
	struct Node	*new_node;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		printf("oh sorry! memmory allocation failed!\n");
		perror("malloc");
		free(new_node);
		exit(1);
	}
	new_node->data = elem;
	new_node->next = *head; /*set new node next to previous node adress*/
	*head = new_node; /*updat head pointer to point to new node*/
}

/*define a function to print*/

void	display(struct Node *node)
{
	struct Node	*temp;

	temp = node;
	printf("Head ");
	while (temp != NULL)
	{
		printf("->[%d] ", temp->data);
		temp = temp->next;
	}
    printf("\n");
}

/**/

/*Driver code*/

int	main(void)
{
	struct Node *head;
	head = NULL;

	int i, no_elem, elem;

	printf("How many elements you want to link? ");
	scanf("%d", &no_elem);

	for (i = 0; i < no_elem; i++)
	{
		/* code */

		printf("Enter Element [%d] ", i + 1);
		scanf("%d", &elem);

		insert_begin(elem, &head);
		display(head);
	}
}