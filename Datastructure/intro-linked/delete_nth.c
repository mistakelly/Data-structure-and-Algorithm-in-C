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

void	pop(int pos, struct Node **head)
{
	struct Node	*temp;
	struct Node	*previous;
	int			size;
	int			i;

	size = listSize(*head);
	temp = *head;
	previous = NULL;
	/**check for invalid position*/
	if (pos > size || pos < 0)
	{
		printf("Invalid position\n");
		exit(1);
	}
	/**case where theres only one node in the list*/
	if (temp->next == NULL)
	{
		*head = NULL;
		printf("deleted the element at index [%d]\n", pos);
		free(temp);
		return ;
	}
	/*to delete element at index 0*/
	if (pos == 0)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	/*deleting at nth index*/
	while (pos != 1)
	{
		/* code */
		temp = temp->next;
		pos--;
	}
	/**Linking the nodes back*/
	previous = temp->next;
	temp->next = previous->next;
	free(previous);
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
	node3->next = node4;
	node4->data = 20;
	node4->next = NULL;

    /*function calls*/
	print_node(head);
	pop(3, &head); /*function to delete Node*/
	print_node(head);
}
