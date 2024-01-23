#include "sort.h"

/**
 * insertion_sort_list - function takes a double pointer to doubly linked list
 * @list: Dobule linked list to sort
 * Return: null
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 *swap_node - It swaps a node from its initial position
 *@node: pointer to the current node
 *@list: pointer to a pointer to to the head of the list
 *Return: returns a pointer to the node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
