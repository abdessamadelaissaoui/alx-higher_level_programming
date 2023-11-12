#include "lists.h"

/*
 * insert_dnodeint_at_index - Inserts a new node in a dlistint_t
 *                            list at a given position.
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The position to insert the new node.
 * @n: The integer for the new node to contain.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *tmp = *h, *new;

    /* If the index is 0, insert at the beginning of the list. */
    if (idx == 0)
        return (add_dnodeint(h, n));

    /* Traverse the list to reach the desired position. */
    for (; idx != 1; idx--)
    {
        tmp = tmp->next;
        if (tmp == NULL)
            return (NULL);
    }

    /* If the desired position is at the end, insert at the end of the list. */
    if (tmp->next == NULL)
        return (add_dnodeint_end(h, n));

    /* Allocate memory for the new node. */
    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    /* Set the value of the new node and update the links. */
    new->n = n;
    new->prev = tmp;
    new->next = tmp->next;
    tmp->next->prev = new;
    tmp->next = new;

    return (new);
}


8-delete_dnodeint.c

#include "lists.h"

/*
 * delete_dnodeint_at_index - Deletes a node from a dlistint_t
 *                            at a given index.
 * @head: A pointer to the head of the dlistint_t.
 * @index: The index of the node to delete.
 *
 * Return: Upon success - 1.
 *         Otherwise - -1.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;

    /* If the list is empty, return -1 indicating failure. */
    if (*head == NULL)
        return (-1);

    /* Traverse the list to reach the desired index. */
    for (; index != 0; index--)
    {
        if (tmp == NULL)
            return (-1);
        tmp = tmp->next;
    }

    /* If the node to delete is the head node. */
    if (tmp == *head)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    /* If the node to delete is not the head node. */
    else
    {
        tmp->prev->next = tmp->next;
        if (tmp->next != NULL)
            tmp->next->prev = tmp->prev;
    }

    /* Free the memory of the deleted node. */
    free(tmp);
    return (1);
}
