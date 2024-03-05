#include <stdio.h>
#include <stdlib.h>

struct Node
{
    /* data */
    int data;
    struct Node *next;
};


int count_nodes(struct Node *head)
{

    struct Node* current = head;

    int count = 0;


    while (current != NULL)
    {
        /* code */
        count++;
        current = current -> next;
    }    

    return count;
    
}

int main(int argc, char *argv[])
{

    struct Node* head = NULL;
    struct Node* node1 = NULL;

    // create list and allocate memory.
     node1 = (struct Node*)malloc(sizeof(struct Node));

     node1->data = 5;
     node1->next = NULL;

     printf("%d\n", node1->data);

     free(node1);

    return 0;
}