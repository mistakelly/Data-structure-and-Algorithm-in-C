#include <stdio.h>
#include <stdlib.h>
#define kelly main

/*define node*/

struct Node
{
    int data;
    struct Node *next;
};


int kelly(void)
{
    /*define head pointer*/

    struct Node *head = NULL;

    /*create a node*/

    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node *)malloc(sizeof(struct Node));

    node1->data = 5;
    
    node1->next = node2;

    node2->data = 10;
    node2-> next = NULL;

    printf("%d %d\n", node1->data, node2->data);

    free(node1);
    return 0;
}