#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

int	main(void)
{
	struct Node *head;
	struct Node *element2;

	head = NULL;

	struct Node *element;

	element = (struct Node *)malloc(sizeof(struct Node));
	element2 = (struct Node *)malloc(sizeof(struct Node));
	head = element;

	element->data = 5;
	element->next = element2;

	element2->data = 10;
	element2->next = NULL;

	// head -> next = NULL;
	struct Node *temp;

	temp = head;

	// temp = temp->next;

	while (temp != NULL)
	{
		/* code */
		printf("%d\n", temp->data);
		printf("temp data [%p] temp -> next [%p]\n", &temp->data, temp->next);
		temp = temp->next;
	}

	printf("address of the head [%p]\n", head);
	printf("address of the temp [%p]\n", temp);

	// printf("memory address of temp 2 [%p]\n", temp);
	// printf("element %d address of the element2 [%p]\n", element2->data,
	// &element2->data);

	return (0);
}