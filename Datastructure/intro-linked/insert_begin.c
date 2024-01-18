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

	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

	if (newnode == NULL)
	{
		printf("malloc failed");
		exit(1);
	}

	newnode->data = 40;
	newnode->next  = NULL;

	printf("{%d}")
	/*creation of node*/

}