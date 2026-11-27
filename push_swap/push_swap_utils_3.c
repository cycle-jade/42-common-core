#include "push_swap.h"

t_node	*find_min_a(t_stack_a *stack_a)
{
	t_node	*current;
	long	min_num;
	t_node	*min_node;

	current = stack_a->first_el;
	min_num = LONG_MAX;
	while (current != NULL)
	{
		if (current->num < min_num)
		{
			min_num = current->num;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max_b(t_stack_b *stack_b)
{
	t_node	*current;
	long	max_num;
	t_node	*max_node;

	current = stack_b->first_el;
	max_num = LONG_MIN;
	while (current != NULL)
	{
		if (current->num > max_num)
		{
			max_num = current->num;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

void	se_above_median_a(t_stack_a *stack_a, int median)
{
	t_node	*current;

	current = stack_a->first_el;
	while (current != NULL)
	{
		if (current->index >= median - 1)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
	}
}

void	se_above_median_b(t_stack_b *stack_b, int median)
{
	t_node	*current;

	current = stack_b->first_el;
	while (current != NULL)
	{
		if (current->index >= median - 1)
			current->above_median = true;
		else
			current->above_median = false;
		current = current->next;
	}
}

void	sort_three(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*max;
	t_node	*min;

	max = find_max_a(stack_a);
	min = find_min_a(stack_a);
	if (max->index == 2)
		ra(stack_a, true);
	else if (max->index == 1)
		rra(stack_a, true);
	set_index(stack_a, stack_b);
	if (min->index == 1)
		sa(stack_a);
}
