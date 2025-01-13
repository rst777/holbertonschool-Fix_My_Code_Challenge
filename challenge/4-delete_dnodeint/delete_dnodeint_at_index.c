#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{

	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL) /* If the list is empty, return failure */
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
    /* Traverse the list to find the node at the specified index */
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
    /* If the index is out of range */
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
    /* Deleting the node at the specific index */
	if (p == 0) /* Special case for deleting the first node */
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else /* Deleting a node other than the first one */
	{
		(*head)->prev->next = (*head)->next;

		if ((*head)->next != NULL)
			(*head)->next->prev = (*head)->prev;

		free(*head);
		*head = saved_head;
	}
	return (1); /* Successful deletion */
}
