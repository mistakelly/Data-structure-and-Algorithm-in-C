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


    print_node(head);


}