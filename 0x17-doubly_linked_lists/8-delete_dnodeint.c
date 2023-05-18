#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes a node at index of a
 * dlistint_t linked list
 *
 * @head: head of a list
 * @index: index of a new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h3;
	dlistint_t *h4;
	unsigned int t;

	h3 = *head;

	if (h3 != NULL)
		while (h3->prev != NULL)
			h3 = h3->prev;

	t = 0;

	while (h3 != NULL)
	{
		if (t == index)
		{
			if (t == 0)
			{
				*head = h3->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				h4->next = h3->next;

				if (h3->next != NULL)
					h3->next->prev = h4;
			}

			free(h3);
			return (1);
		}
		h4 = h3;
		h3 = h3->next;
		t++;
	}

	return (-1);
}
