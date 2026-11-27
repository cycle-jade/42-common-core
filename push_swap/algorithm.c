#include "push_swap.h"

void	moves_a(t_node *current, t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (current->target_node->cost != 0
		&& current->target_node->above_median == true)
		rb(stack_b, true);
	else if (current->target_node->cost != 0
		&& current->target_node->above_median == false)
		rrb(stack_b, true);
	init_node_a(stack_a, stack_b);
	if (current->cost != 0)
	{
		if (current->strike == true && current->above_median == true
			&& current->target_node->above_median == false)
			rr(stack_a, stack_b);
		else if (current->strike == true && current->above_median == false
			&& current->target_node->above_median == false)
			rrr(stack_a, stack_b);
		else if (current->above_median == true)
			ra(stack_a, true);
		else if (current->above_median == false)
			rra(stack_a, true);
	}
}

void	moves_b(t_node *current, t_stack_a *stack_a, t_stack_b *stack_b)
{
	if (current->target_node->cost != 0
		&& current->target_node->above_median == true)
		ra(stack_a, true);
	else if (current->target_node->cost != 0
		&& current->target_node->above_median == false)
		rra(stack_a, true);
	if (current->cost != 0)
	{
		if (current->strike == true && current->above_median == true
			&& current->target_node->above_median == true)
			rr(stack_a, stack_b);
		else if (current->strike == true && current->above_median == false
			&& current->target_node->above_median == false)
			rrr(stack_a, stack_b);
		else if (current->above_median == true)
			rb(stack_b, true);
		else if (current->above_median == false)
			rrb(stack_b, true);
	}
}

void	algo_stack_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;

	if (get_stack_lenght_a(stack_a) != 4)
		pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (get_stack_lenght_a(stack_a) > 3)
	{
		current = init_node_a(stack_a, stack_b);
		while (current->cost != 0 || current->target_node->cost != 0)
		{
			moves_a(current, stack_a, stack_b);
			init_node_a(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
	}
	algo_stack_b(stack_a, stack_b);
}

void	algo_stack_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;

	if (is_sorted(stack_a) == false)
		sort_three(stack_a, stack_b);
	while (get_stack_lenght_b(stack_b) != 0)
	{
		current = init_node_b(stack_a, stack_b);
		while (current->cost != 0 || current->target_node->cost != 0)
		{
			moves_b(current, stack_a, stack_b);
			init_node_b(stack_a, stack_b);
		}
		pa(stack_a, stack_b);
	}
	algo_finals(stack_a, stack_b);
}

void	algo_finals(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;

	current = find_min_a(stack_a);
	set_index(stack_a, stack_b);
	while (current->index != get_stack_lenght_a(stack_a) - 1)
	{
		if (current->above_median == true)
			ra(stack_a, true);
		else
			rra(stack_a, true);
		set_index(stack_a, stack_b);
	}
}
