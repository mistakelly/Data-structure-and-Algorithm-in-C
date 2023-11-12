#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

void	pop_begin(int pos, struct Node **head)
{
	struct Node	*temp;

	temp = *head;
	if (pos == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
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
	struct Node *head = NULL;
	struct Node *node2 = NULL;
	struct Node *node3 = NULL;
	struct Node *node4 = NULL;
	struct Node *node5 = NULL;
	struct Node *node6 = NULL;

	// allocate 3 nodes in the heap
	node2 = (struct Node *)malloc(sizeof(struct Node));
	node3 = (struct Node *)malloc(sizeof(struct Node));
	node4 = (struct Node *)malloc(sizeof(struct Node));
	node5 = (struct Node *)malloc(sizeof(struct Node));
	node6 = (struct Node *)malloc(sizeof(struct Node));

	head = node2;

	node2->data = 80;
	node2->next = node3;

	node3->data = 24;
	node3->next = node4;

	node4->data = 20;
	node4->next = node5;

	node5->data = 16;
	node5->next = node6;

	node6->data = 12;
	node6->next = NULL;

	display(head);
	pop_begin(0, &head);

	display(head);
}

