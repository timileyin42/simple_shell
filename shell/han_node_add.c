#include "main.h"

/**
  * add_line_node_end - Functions that helps append command line at the end
  * of buf_store.
  * @head: A double pointer pointing to the head of a linked list.
  * @buffer: A pointer to the command line.
  * Return: Address of the linked list head.
  */

buf_store *add_line_node_end(buf_store **head, char *buffer)
{
	buf_store *hold, *temp;

	hold = malloc(sizeof(buf_store));
	if (hold == NULL)
		return (NULL);

	hold->buffer = buffer;
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
 * buf_store_free - Functions that helps free memory of buf_store
 * @head: A double pointer to the head of a linked list.
 * Return: Always (void)
 */

void buf_store_free(buf_store **head)
{
	buf_store *temp, *current;

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

/**
 * add_sep_node_end - Functions that helps add a separator at the end of a
 * list_div.
 * @head: A double pointer pointing to the head of a linked list
 * @div: A buffer to the separator found (; | &).
 * Return: Address of the head.
 */

list_div *add_sep_node_end(list_div **head, char div)
{
	list_div *hold, *temp;

	hold = malloc(sizeof(list_div));
	if (hold == NULL)
		return (NULL);

	hold->separator = div;
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
 * list_div_free - Functions that helps free the list_div after use
 * @head: A double pointer pointing to the head of linked list.
 * Return: Always (void)
 */

void list_div_free(list_div **head)
{
	list_div *temp, *current;

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
