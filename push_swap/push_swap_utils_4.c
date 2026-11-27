#include "push_swap.h"

t_node	*find_max_a(t_stack_a *stack_a)
{
	t_node	*current;
	long	max_num;
	t_node	*max_node;

	current = stack_a->first_el;
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

bool	is_sorted(t_stack_a *stack_a)
{
	t_node	*current;
	t_node	*next;

	current = stack_a->first_el;
	while (current->next != NULL)
	{
		next = current->next;
		if (current->num < next->num)
			return (false);
		current = current->next;
	}
	return (true);
}

t_node	*get_node_from_index_a(t_stack_a *stack_a, int index)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack_a->first_el;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}

t_node	*get_node_from_index_b(t_stack_b *stack_b, int index)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack_b->first_el;
	while (i < index)
	{
		current = current->next;
		i++;
	}
	return (current);
}
