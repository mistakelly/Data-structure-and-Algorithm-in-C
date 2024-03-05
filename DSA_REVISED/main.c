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

    struct Node* current = NULL;
    // current = head;

    int count = 0;
    while (head != NULL)
    {
        /* code */
        printf("address of head <%p>\n", head);
        count++;
        head = head -> next;
    }    
    return count;
}

int main(int argc, char *argv[])
{

    struct Node* head = NULL;
    struct Node* node1 = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;
    struct Node* node4 = NULL;
    
    // create list and allocate memory.
     node1 = (struct Node*)malloc(sizeof(struct Node));
     node2 = (struct Node*)malloc(sizeof(struct Node));
     node3 = (struct Node*)malloc(sizeof(struct Node));
     node4 = (struct Node*)malloc(sizeof(struct Node));

    head = node1;
    
    
     node1->data = 5;
     node1->next = node2;

     node2->data = 10;
     node2->next = node3;

     node3->data = 15;
     node3->next = node4;

     node4->data = 20;
     node4->next = NULL;
    int count = count_nodes(head);

     printf("%d\n", node1->data);
     printf("%d\n", node2->data);
     printf("%d\n", node3->data);
     printf("%d\n", node4->data);
     
     int i = 1;

     while (head != NULL)
     {
        /* code */

        printf("address of the node {%d} elem {%d} <%p>\n",  i, head->data, &head->data);
        // printf("address of head itself after printing <%p>\n", head);
        head = head->next;
        i++;
     }


     printf("address of head itself after printing <%p>\n", &head);
     

    // printf("address of head <%p>\n", head);
     
     printf("sizeof nodes <%d>\n", count);

     free(node1);
     free(node2);
     free(node3);
     free(node4);

    return 0;
}