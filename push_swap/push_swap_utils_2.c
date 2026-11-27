#include "push_swap.h"

void	calculate_cost(t_stack_a *stack_a, t_stack_b *stack_b, int median)
{
	t_node	*current;

	current = stack_a->first_el;
	while (current != NULL)
	{
		if (current->index < median - 1 && get_stack_lenght_a(stack_a) > 2)
			current->cost = current->index + 1;
		else
			current->cost = get_stack_lenght_a(stack_a) - current->index - 1;
		current = current->next;
	}
	current = stack_b->first_el;
	median = find_median_b(stack_b);
	while (current != NULL)
	{
		if (current->index < median - 1 && get_stack_lenght_b(stack_b) > 2)
			current->cost = current->index + 1;
		else
			current->cost = get_stack_lenght_b(stack_b) - current->index - 1;
		current = current->next;
	}
}

int	find_min_cost_a(t_stack_a *stack_a)
{
	t_node	*current;
	long	min_num;
	t_node	*min_node;
	int		cost;

	cost = 0;
	current = stack_a->first_el;
	min_num = LONG_MAX;
	while (current != NULL)
	{
		cost = current->cost;
		if (current->index == current->target_node->index && current->index > 0
			&& current->cost == current->target_node->cost)
		{
			current->strike = true;
			cost -= current->target_node->cost;
		}
		if (cost + current->target_node->cost <= min_num)
		{
			min_num = cost + current->target_node->cost;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node->index);
}

int	find_min_cost_b(t_stack_b *stack_b)
{
	t_node	*current;
	long	min_num;
	t_node	*min_node;
	int		cost;

	cost = 0;
	current = stack_b->first_el;
	min_num = LONG_MAX;
	while (current != NULL)
	{
		cost = current->cost;
		if (current->index == current->target_node->index && current->index > 0
			&& current->cost == current->target_node->cost)
		{
			current->strike = true;
			cost -= current->target_node->cost;
		}
		if (cost + current->target_node->cost < min_num)
		{
			min_num = cost + current->target_node->cost;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node->index);
}

void	find_closest_a(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current_a;
	t_node	closest;
	t_node	*current_b;

	current_a = stack_a->first_el;
	while (current_a != NULL)
	{
		current_b = stack_b->first_el;
		closest.num = LONG_MIN;
		while (current_b != NULL)
		{
			if (current_b->num < current_a->num && current_b->num > closest.num)
			{
				closest.target_node = current_b;
				closest.num = current_b->num;
			}
			current_b = current_b->next;
		}
		current_a->target_node = closest.target_node;
		if (closest.num == LONG_MIN)
			current_a->target_node = find_max_b(stack_b);
		current_a = current_a->next;
	}
}

void	find_closest_b(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current_a;
	t_node	closest;
	t_node	*current_b;

	current_b = stack_b->first_el;
	while (current_b != NULL)
	{
		current_a = stack_a->first_el;
		closest.num = LONG_MAX;
		while (current_a != NULL)
		{
			if (current_a->num > current_b->num && current_a->num < closest.num)
			{
				closest.target_node = current_a;
				closest.num = current_a->num;
			}
			current_a = current_a->next;
		}
		current_b->target_node = closest.target_node;
		if (closest.num == LONG_MAX)
			current_b->target_node = find_min_a(stack_a);
		current_b = current_b->next;
	}
}
