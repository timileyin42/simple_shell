#include "main.h"

/**
 * node_va - Functions that helps add variables at the end of a v_shell list
 * @head: A double pointer pointing to the head of linked list.
 * @var_len: Length of the variable
 * @buffer: the valuse of the variable.
 * @val_len: length of the value.
 * Return: Address of the head.
 */

v_shell *node_va(v_shell **head, int var_len, char *buffer, int val_len)
{
	v_shell *hold, *temp;

	hold = malloc(sizeof(v_shell));
	if (*head == NULL)
		return (NULL);

	hold->var_size = var_len;
	hold->value = buffer;
	hold->value_len = val_len;

	hold->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = hold;
	}
	else
	{
		for (; temp->next != NULL; temp = temp->next)
		{
			/* loop through */
		}
		temp->next = hold;
	}
	return (*head);
}

/**
 * node_va_free - Functions that helps free
 * @head: A double pointer pointing to the head of linked list.
 * Return: Always (void)
 */

void node_va_free(v_shell **head)
{
	v_shell *temp, *current;

	if (head != NULL)
	{
		current = *head;
		for (; current != NULL; current = temp)
		{
			temp = current->next;
			free(current);
		}
		*head = NULL;
	}
}
