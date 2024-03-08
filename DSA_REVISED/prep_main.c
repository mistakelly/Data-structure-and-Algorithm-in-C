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


    node *head, *first_node, *second_node, *third_node, *tmp  = NULL;
    first_node = (node *)malloc(sizeof(node));
    second_node = (node *)malloc(sizeof(node));
    third_node = (node *)malloc(sizeof(node));

    /*connect the head pointer to the nodes*/
    head = first_node;

    first_node->data = 5;
    first_node->next = second_node;
    g
    second_node->data = 10;
    second_node->next = third_node;

    third_node->data = 15;
    third_node->next = NULL;


    /*print list*/
    print_list(head);

    /*free head*/
    free_mem(head);
    return 0;
}