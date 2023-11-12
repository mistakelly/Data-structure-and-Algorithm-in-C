#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*next;
};

int	main(void)
{
	struct Node	*head;
	struct Node	*element;
	struct Node	*element2;
	struct Node	*element3;
	struct Node	*temp;
	int			pos;

	head = NULL;
	element = (struct Node *)malloc(sizeof(struct Node));
	element2 = (struct Node *)malloc(sizeof(struct Node));
	element3 = (struct Node *)malloc(sizeof(struct Node));
	head = element;
	temp = head;
	element->data = 5;
	element->next = element2;
	element2->data = 10;
	element2->next = element3;
	// printf("address of element2 ->next [%p]\n", element2->next);
	element3->data = 59;
	element3->next = NULL;
	printf("address of element2 ->next [%p]\n", element3->next);
	// while (temp != NULL && temp->next != NULL && temp->next->next != NULL)
	while (temp != NULL)
	{
		/* code */
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	// printf("address of the first element [%p]\n", element2);
	printf("address of the last element [%p]\n", &element3->data);
	// printf("address of the head [%d]\n", head->next->next->data);
	printf("address of the temp [%p]\n", temp);
	return (0);
}
