#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    /* data */
    int data;
    struct Node *next;
}node;


/*func to print list*/
void print_list(node *head)
{

    while (head != NULL)
    {
        /* code */
        printf("link->%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_mem(node *head)
{
    node *tmp = NULL;
    while (head != NULL)
    {
        /* code */

        /*set head to tmp so we can alway free the firstnode*/
        tmp = head;
        head = head->next;
        free(tmp);

    }
}

/*Driver code*/
int main(int argc, char *argv[])
{
    node *head = NULL;
    
    node c = {15, NULL};
    
    node b = {10, &c};

    node a = {5, &b};

    head = &a;

    print_list(head);    
    return 0;
}