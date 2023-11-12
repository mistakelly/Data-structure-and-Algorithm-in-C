#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

int	listSize(struct Node *head)
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
void	pop_nth(int pos, struct Node **head)
{
	int			size;
	struct Node	*temp;
	struct Node	*previous;

	size = listSize(*head);
	if (pos >= size || pos < 0)
	{
		printf("Invalid Position\n");
		exit(1);
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
			/* code */
			previous = temp;
			temp = temp->next;
			pos--;
		}
		/**Linking Nodes    */
		previous->next = temp->next;
		free(temp);
	}
}
/**function to print*/
void	print_node(struct Node *head)
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

int	main(void)
{
	struct Node	*head;
	struct Node	*node1;
	struct Node	*node2;
	struct Node	*node3;
	struct Node	*node4;

	head = NULL;
	node1 = NULL;
	node2 = NULL;
	node3 = NULL;
	node4 = NULL;
	/**creat four nodes to be linked together*/
	node1 = (struct Node *)malloc(sizeof(struct Node));
	node2 = (struct Node *)malloc(sizeof(struct Node));
	node3 = (struct Node *)malloc(sizeof(struct Node));
	node4 = (struct Node *)malloc(sizeof(struct Node));
	/*link head to the first node*/
	head = node1;

	/*assinging elements and links in nodes*/
	node1->data = 5;

	node1->next = node2;
	node2->data = 10;

	node2->next = node3;
	node3->data = 15;

	// printf("address of node 3 [%p]\n", node3->data);
	node3->next = node4;
	node4->data = 20;
	node4->next = NULL;

	/*function calls*/
	print_node(head);
	pop_nth(0, &head); /*function to delete Node*/
	print_node(head);
    printf("address of head [%p]\n", head);
}
