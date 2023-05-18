#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts the current node at
 * a given position
 *
 * @h: head of a list
 * @idx: index of the current node
 * @n: value of a current node
 * Return: the address of a current node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *head;
	unsigned int t;

	current = NULL;
	if (idx == 0)
		current = add_dnodeint(h, n);
	else
	{
		head = *h;
		t = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (t == idx)
			{
				if (head->next == NULL)
					current = add_dnodeint_end(h, n);
				else
				{
					current = malloc(sizeof(dlistint_t));
					if (current != NULL)
					{
						current->n = n;
						current->next = head->next;
						current->prev = head;
						head->next->prev = current;
						head->next = current;
					}
				}
				break;
			}
			head = head->next;
			t++;
		}
	}

	return (current);
}
