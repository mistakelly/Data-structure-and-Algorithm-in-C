#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int	top;
	int	size;
	int	*array;
}		stack;

/*push function*/

void	create_stack(stack *st)
{
	st->top = -1;
	printf("How many elements you wanna add to the stack? ");
	scanf("%d", &st->size);
	/*create memory for the array*/
	st->array = (int *)malloc(st->size * sizeof(int));
}

void	push(stack *st, int element)
{
	/*check if stack is filled up*/
	if (st->top == st->size - 1)
	{
		fprintf(stderr, "Stack Overflow!\n");
		return ;
	}
	st->array[++st->top] = element;
}

void	print(stack st)
{
	int	i;

	for (i = st.top; i >= 0; i--)
		printf("%d ", st.array[i]);
	printf("\n");
}

int	pop(stack *st)
{
	int	index;

	index = -1;
	if (st->top == -1)
		fprintf(stderr, "Stack UnderFlow\n");
	else
		index = st->array[st->top--];
	return (index);
}

/*Function to check if stack is Empty*/
bool	isEmpty(stack *st)
{
	return (st->top == -1);
}

/*Function to return the first Element in the stack*/

int	stack_top(stack *st)
{
	return (st->array[st->top]);
}

/*Function to return the index of Element in the stack*/

int	peeky(stack *st, int pos)
{
	/*formula == top - position + 1*/
	return (st->array[st->top - pos + 1]);
}

int	main(void)
{
	stack st;

	create_stack(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);
	printf("%d\n", pop(&st));
	printf("stack top %d\n", stack_top(&st));
    printf("peeky %d\n", peeky(&st, 0));

	print(st);

	free(st.array);
}