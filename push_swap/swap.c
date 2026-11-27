#include "push_swap.h"

void	sa(t_stack_a *stack_a)
{
	t_node	*switchin;

	if (stack_a->last_el == NULL || stack_a->first_el->next == NULL)
	{
		return ;
	}
	switchin = stack_a->last_el;
	stack_a->last_el->next = stack_a->last_el->previous;
	stack_a->last_el = stack_a->last_el->previous;
	switchin->previous = stack_a->last_el->previous;
	stack_a->last_el->next = NULL;
	stack_a->last_el->previous = switchin;
	switchin = switchin->previous;
	if (switchin != NULL)
		switchin->next = stack_a->last_el->previous;
	else
		stack_a->first_el = stack_a->last_el->previous;
	ft_printf("sa\n");
}

void	sb(t_stack_b *stack_b)
{
	t_node	*switchin;

	if (stack_b->last_el == NULL || stack_b->first_el->next == NULL)
	{
		return ;
	}
	switchin = stack_b->last_el;
	stack_b->last_el->next = stack_b->last_el->previous;
	stack_b->last_el = stack_b->last_el->previous;
	switchin->previous = stack_b->last_el->previous;
	stack_b->last_el->next = NULL;
	stack_b->last_el->previous = switchin;
	switchin = switchin->previous;
	if (switchin != NULL)
		switchin->next = stack_b->last_el->previous;
	else
		stack_b->first_el = stack_b->last_el->previous;
	ft_printf("sb\n");
}

void	ss(t_stack_a *stack_a, t_stack_b *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
}
