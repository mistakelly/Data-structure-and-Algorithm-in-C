#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    /* data */
    int data;
    struct Node *next;
} node;

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

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node node[5];

    for (size_t i = 0; i < 5; i++)
    {
        /* code */
       node[i].data = arr[i];
       node[i].next = NULL;
    }
    

    for (size_t i = 0; i < 5; i++)
    {
        /* code */
      printf("%d -> ", node[i].data);
    }
    printf("NULL\n");

    return 0;
}
