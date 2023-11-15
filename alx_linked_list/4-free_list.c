#include "lists.h"

/**
 * free_list - frees a linked list
 * @head: list_t list to be freed
 */
void free_list(list_t *head)
{
    list_t *temp;

    while (head)
    {
        temp = head->next;   // Store the reference to the next node
        free(head->str);      // Free the memory allocated for the string in the current node
        free(head);           // Free the memory allocated for the current node
        head = temp;          // Move to the next node
    }
}
