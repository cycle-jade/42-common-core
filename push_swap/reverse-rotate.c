#include "push_swap.h"

void	rra(t_stack_a *stack_a, bool print)
{
	t_node	*next;

	if (stack_a->last_el == NULL || stack_a->first_el->next == NULL)
	{
		return ;
	}
	next = stack_a->first_el->next;
	stack_a->last_el->next = stack_a->first_el;
	stack_a->first_el->previous = stack_a->last_el;
	stack_a->first_el = next;
	stack_a->first_el->previous = NULL;
	stack_a->last_el = stack_a->last_el->next;
	stack_a->last_el->next = NULL;
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_b *stack_b, bool print)
{
	t_node	*next;

	if (stack_b->last_el == NULL || stack_b->first_el->next == NULL)
	{
		return ;
	}
	next = stack_b->first_el->next;
	stack_b->last_el->next = stack_b->first_el;
	stack_b->first_el->previous = stack_b->last_el;
	stack_b->first_el = next;
	stack_b->first_el->previous = NULL;
	stack_b->last_el = stack_b->last_el->next;
	stack_b->last_el->next = NULL;
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr\n");
}
