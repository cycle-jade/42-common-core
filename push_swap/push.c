#include "push_swap.h"

void	pb(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*previous;

	if (stack_a->last_el == NULL)
		return ;
	previous = stack_a->last_el->previous;
	if (stack_b->last_el != NULL)
		stack_b->last_el->next = stack_a->last_el;
	stack_a->last_el->previous = stack_b->last_el;
	stack_b->last_el = stack_a->last_el;
	stack_a->last_el = previous;
	if (previous != NULL)
		stack_a->last_el->next = NULL;
	if (stack_b->first_el == NULL)
		stack_b->first_el = stack_b->last_el;
	if (previous == NULL)
		stack_a->first_el = stack_a->last_el;
	ft_printf("pb\n");
}

void	pa(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*node_to_move;

	if (stack_b->last_el == NULL)
		return ;
	node_to_move = stack_b->last_el;
	stack_b->last_el = node_to_move->previous;
	if (stack_b->last_el != NULL)
		stack_b->last_el->next = NULL;
	else
		stack_b->first_el = NULL;
	node_to_move->previous = stack_a->last_el;
	node_to_move->next = NULL;
	if (stack_a->last_el != NULL)
		stack_a->last_el->next = node_to_move;
	else
		stack_a->first_el = node_to_move;
	stack_a->last_el = node_to_move;
	ft_printf("pa\n");
}
