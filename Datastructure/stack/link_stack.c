#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int				data;
	struct stack	*next;
}					Stack;

/* sizeof the stack */

int	list_size(Stack *top)
{
	int	size;

	size = 0;
	while (top != NULL)
	{
		size++;
		top = top->next;
	}
	return (size);
}

/*push function*/
void	push(Stack **top, int data)
{
	Stack	*element;

	element = (Stack *)malloc(sizeof(Stack));
	// element->next = NULL;
	if (element == NULL)
	{
		fprintf(stderr, "Memory Allocation Failed\n");
		return ;
	}
	else
	{
		element->data = data;
		element->next = *top;
		*top = element;
	}
}

/*pop Function*/

int	pop(Stack **top)
{
	Stack	*temp;
	int		data;

	if (*top == NULL)
	{
		fprintf(stderr, "Stack is empty\n");
		return (-1);
	}
	temp = *top;
	data = (*top)->data;
	*top = temp->next;
	free(temp);
	return (data);
}

/*is Empty*/

bool	is_empty(Stack **top)
{
	return (*top == NULL);
}

/*top of the stack*/

int	stack_top(Stack **top)
{
	if (*top == NULL)
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return ((*top)->data);
}

/*peek that is the element at a given index*/

int	peek_stack(Stack **top, int pos)
{
	int		size;
	Stack	*temp;

	size = list_size(*top);
	if ((*top) == NULL)
	{
		fprintf(stderr, "Error! Stack is Empty\n");
		return (-1);
	}
	if (pos < 0 || pos >= size)
	{
		fprintf(stderr, "Out Of Index\n");
		exit(1);
	}
	else
	{
		temp = *top;
		while (pos > 0)
		{
			temp = temp->next;
			pos--;
		}
	}
	return (temp->data);
}

/*print Function*/
void	print(Stack *top)
{
	Stack	*temp;

	temp = top;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int	main(void)
{
	Stack	*top;

	top = NULL;
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);
	push(&top, 50);
	printf("%d\n", peek_stack(&top, 4));
	print(top);
}
