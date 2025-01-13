#include "lists.h"
#include <stdlib.h>

/**
* delete_dnodeint_at_index - Deletes the node at a specific index from
* a doubly linked list.
* @head: A double pointer to the first element of the list.
* @index: The index of the node to delete (starting from 0).
*
* Return: 1 if the deletion was successful, -1 if it failed
* (e.g., index out of range).
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p;

	/* Check if the list is empty*/
	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;  /* Start at the beginning of the list */
	p = 0;

	/* Traverse the list to find the node at the given index */
	while (current != NULL && p < index)
	{
		current = current->next;  /* Move to the next node */
		p++;
	}

	/* If index is out of bounds*/
	if (current == NULL || p != index)
		return (-1);

	/* Special case: deleting the first node*/
	if (index == 0)
	{
		*head = current->next;  /* Update head to next node*/
		if (*head != NULL)
			(*head)->prev = NULL;  /* Update previous pointer of new head*/
		free(current);  /* Free memory of the deleted node*/
	}
	else  /* Deleting a node other than the first one*/
	{
		if (current->prev != NULL)  /* Ensure previous node exists*/
			current->prev->next = current->next;
			/* Update next pointer of previous node*/
		if (current->next != NULL)  /*Ensure next node exists*/
			current->next->prev = current->prev;
			/* Update previous pointer of next node*/
		free(current);  /* Free memory of the deleted node */
	}
	return (1);  /* Deletion successful */
}
