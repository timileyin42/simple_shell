#include "holberton.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: the list of elements
 * @args: string to be stored
 * @id: value of the atributte ide (extern or builtin)
 * @cont: cont
 * @name: name
 *
 * Return: direction of the new node
 */
bash_shell *add_node(bash_shell **head, char **args, int id,
		    int cont, char *name)
{
	int flag = 1;
	command_t *p = *head;
	command_t *new = malloc(sizeof(bash_shell));

	do {
		if (!p || !(p->next))
		{
			if (!new)
				return (NULL);
			new->args = args;
			new->id = id;
			new->cont = cont;
			new->name = name;
			new->next = NULL;
			if (!p)
			{
				*head = new;
				return (new);
			}
			p->next = new;
			flag = 0;
		}
		else
			p = p->next;
	} while (flag);
	return (new);
}
