#include "monty.h"
/**
 * push - adds node to the start of dlinkedlist
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (isdigit(atoi(n)) != 0 || (atoi(n) == 0 && *n != '0'))
	{
		printf("L%u: usage: push integer\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - print all nodes in stack
 * @h: head of list
 * @line_number: bytecode line number
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!h || !*h)
		return;

	(void) line_number;
	tmp = *h;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * pint - print top node in stack
 * @h: head of list
 * @line_number: bytecode line number
 */
void pint(stack_t **h, unsigned int line_number)
{
	if (!h || !*h)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*h)->n);
}
