#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*defining a macro for the main*/
#define kelly main

/*define a structure*/

struct Node
{
    int data;
    struct Node *next;
};

/*printing the list*/

void print_node(struct Node *head)
{
    while(head != NULL)
    {
        print("{%d}", head->data);
        head = head -> next;
    }
}

/**using my name for the main function*/
int kelly(int argc, char **argv)
{

    struct Node *head;
    head = NULL;

    int array[] = {1,2,3,4,5}; 

    for(int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        /**allocate memory for the Nodes*/

        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

        if(newnode == NULL)
        {
            printf("")
        }

    }


    print_node(head);

    return 0;

}