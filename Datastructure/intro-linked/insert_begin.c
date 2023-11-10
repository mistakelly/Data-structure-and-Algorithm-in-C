#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

// function to insert

struct Node	*insert_begin(struct Node *head, int data)
{
	struct Node	*new_node;

	new_node = (struct Node *)malloc(sizeof(struct Node));
	if (new_node == NULL)
	{
		perror("malloc");
		exit(1);
	}
	new_node->data = data;
	if (head != NULL)
	{
		new_node->next = head;
	}
	head = new_node;
	return (head);
}

void	print_node(struct Node *head)
{
	struct Node	*temp;

	temp = head;
	printf("head ");
	while (temp != NULL)
	{
		printf("->[%d] ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int	main(void)
{
	struct Node *head;
	head = NULL;

	int i, n, elem;

	printf("how many elements do you want to link? ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		/* code */

		printf("Enter Element [%d]: ", i + 1);
		scanf("%d", &elem);

		head = insert_begin(head, elem);
		print_node(head);
	}

	return (0);
}