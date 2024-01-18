#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

/**
 * @brief: main function
 * its the driver function of the program
 * @param: argc argument count
 * @param: argv argument variable
 */
int main(int argc, char *argv[])
{
	struct Node *head = NULL;
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	struct Node *newnode2 = (struct Node *)malloc(sizeof(struct Node));

	if (newnode == NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	struct Node *temp = head;
	
	head->next = newnode;
	newnode->data = 40;
	newnode->next  = newnode2;
	newnode2->data = 60;
	newnode2->next = NULL;

	while(temp)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}

	free(newnode);

	return 0;
	/*creation of node*/

}