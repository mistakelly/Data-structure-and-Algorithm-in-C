#include <stdio.h>
#include <stdlib.h>

struct			Node
{
	int			data;
	struct Node	*link;
};

int	main(void)
{
	struct Node	*head_pointer;
	struct Node	*temp_pointer;
	struct Node	*score;
	struct Node	*second_score;
	struct Node	*third_score;
	struct Node	*fourth_score;

	/*define a head pointer*/
	/*define a pointer to hold the address of the first byte of the allocated memeory in the heap*/
	score = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter an element: ");
	scanf("%d", &score->data);
	/*check if malloc should fail*/
	if (score == NULL)
	{
		perror("malloc");
		exit(1);
	}
	/*add element to the allocated address*/
	// score->data = 5;
	/*assign the address of the first Node to the head_pointer so that the link will have somewhere to start from when you want to start printing elements in the linked list*/
	head_pointer = score;
	/*add another score to the linked list*/
	second_score = (struct Node *)malloc(sizeof(struct Node));
	/*add element to the allocated address*/
	printf("Enter an 2nd element: ");
	scanf("%d", &second_score->data);
	/*check if malloc should fail*/
	if (second_score == NULL)
	{
		perror("malloc");
		exit(1);
	}
	/*link the first Node to the second Node*/
	if (head_pointer != NULL)
	{
		score->link = second_score;
	}
	third_score = (struct Node *)malloc(sizeof(struct Node));
	/*check if malloc should fail*/
	if (third_score == NULL)
	{
		perror("malloc");
		exit(1);
	}
	/*add element to the allocated address*/
	printf("Enter an 3rd element: ");
	scanf("%d", &third_score->data);
	/*link the first Node to the second Node*/
	if (head_pointer != NULL)
	{
		second_score->link = third_score;
	}
	fourth_score = (struct Node *)malloc(sizeof(struct Node));
	/*check if malloc should fail*/
	printf("Enter  4th element: ");
	scanf("%d", &fourth_score->data);
	if (fourth_score == NULL)
	{
		perror("malloc");
		exit(1);
	}
	/*add element to the allocated address*/
	/*link the first Node to the second Node*/
	if (head_pointer != NULL)
	{
		third_score->link = fourth_score;
	}
	fourth_score->link = NULL;
	/*define a temp pointer for tranversing and printing the Node in order not to mutate the head pointer using the head pointer for tranversing*/
	/**assign the address of head_pointer to temp pointer for tranversing the list*/
	temp_pointer = head_pointer;
	while (temp_pointer != NULL)
	{
		/*printing the element*/
		printf("%d ", temp_pointer->data);
		/*move the temp pointer to point to the next node address*/
		temp_pointer = temp_pointer->link;
	}
	printf("\n");
	/**freeing the allocated memory to avoid memory leaks*/
	free(score);
	free(second_score);
	free(third_score);
	free(fourth_score);
	return (0);
}
