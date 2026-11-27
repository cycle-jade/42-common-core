#include "push_swap.h"

void	ra(t_stack_a *stack_a, bool print)
{
	if (stack_a->last_el == NULL || stack_a->last_el->previous == NULL)
		return ;
	if (stack_a->last_el == stack_a->first_el)
	{
		return ;
	}
	stack_a->last_el->next = stack_a->first_el;
	stack_a->first_el->previous = stack_a->last_el;
	stack_a->last_el = stack_a->last_el->previous;
	stack_a->last_el->next = NULL;
	stack_a->first_el = stack_a->first_el->previous;
	stack_a->first_el->previous = NULL;
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack_b *stack_b, bool print)
{
	if (stack_b->last_el == NULL || stack_b->last_el->previous == NULL)
		return ;
	if (stack_b->last_el == stack_b->first_el)
	{
		return ;
	}
	stack_b->last_el->next = stack_b->first_el;
	stack_b->first_el->previous = stack_b->last_el;
	stack_b->last_el = stack_b->last_el->previous;
	stack_b->last_el->next = NULL;
	stack_b->first_el = stack_b->first_el->previous;
	stack_b->first_el->previous = NULL;
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ra(stack_a, false);
	rb(stack_b, false);
	ft_printf("rr\n");
}
