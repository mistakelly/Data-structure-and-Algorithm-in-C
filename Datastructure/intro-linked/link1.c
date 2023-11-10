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
	struct Node	*scores;
    struct Node *temp;
    struct Node *current;

	head = NULL;
	int i, no_elements;
	printf("how many elements do you want to link?: ");
	scanf("%d", &no_elements);
	for (i = 0; i < no_elements; i++)
	{
		/* code */
		scores = (struct Node *)malloc(sizeof(struct Node));
        if(scores == NULL)
        {
            perror("malloc");
            exit(1);
        }  

        printf("Enter element [%d]: ", i + 1);
        scanf("%d", (&scores->data));

        scores->next = head;
        head = scores;

	}


    /*printing elements*/
    temp = head;

    while (temp != NULL)
    {
        /* code */
        printf("%d ", temp->data);
        temp  = temp -> next;
    }

    printf("\n");

    /*freeing the Nodes*/

    temp = head;

    while(temp != NULL)
    {
        current = temp;
        temp  = temp -> next;

        free(current);
    }



	return (0);
}
