#include "push_swap.h"

t_node	*init_node_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;

	set_index(stack_a, stack_b);
	calculate_cost(stack_a, stack_b, find_median_a(stack_a));
	find_closest_a(stack_a, stack_b);
	se_above_median_a(stack_a, find_median_a(stack_a));
	se_above_median_b(stack_b, find_median_b(stack_b));
	current = get_node_from_index_a(stack_a, find_min_cost_a(stack_a));
	return (current);
}

t_node	*init_node_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;

	set_index(stack_a, stack_b);
	calculate_cost(stack_a, stack_b, find_median_a(stack_a));
	find_closest_b(stack_a, stack_b);
	se_above_median_b(stack_b, find_median_b(stack_b));
	se_above_median_a(stack_a, find_median_a(stack_a));
	current = get_node_from_index_b(stack_b, find_min_cost_b(stack_b));
	return (current);
}
