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
struct Node		*head;
int	getListSize(void)
{
	struct Node	*temp;
	int			size;

	temp = head;
	size = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

/**function to insert element*/

void	insert_nth(int pos, int data)
{
	int			size;
	struct Node	*temp;
	struct Node	*new_node;

	temp = head;
	size = getListSize();
	new_node = (struct Node *)malloc(sizeof(struct Node));
	temp = head;
	new_node->data = data;
	if (pos > size || pos < 0)
	{
		printf("Invalid position\n");
        free(new_node);
        return;
	}
	if (pos == 0)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		while (pos > 1)
		{
			temp = temp->next;
			pos--;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
}

/**printing the nodes*/

void	print_nodes(void)
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
	head = NULL;
	struct Node *node1 = NULL;
	struct Node *node2 = NULL;
	struct Node *node3 = NULL;
	struct Node *node4 = NULL;

	/**creat four nodes to be linked together*/
	node1 = (struct Node *)malloc(sizeof(struct Node));
	node2 = (struct Node *)malloc(sizeof(struct Node));
	node3 = (struct Node *)malloc(sizeof(struct Node));
	node4 = (struct Node *)malloc(sizeof(struct Node));

	/*link head to the first node*/

	head = node1;

	node1->data = 5;
	node1->next = node2;

	node2->data = 10;
	node2->next = node3;

	node3->data = 15;
	node3->next = node4;

	node4->data = 20;
	node4->next = NULL;

	print_nodes();

	insert_nth(4, 900);

	print_nodes();

	printf("[%p]\n", head);
}

