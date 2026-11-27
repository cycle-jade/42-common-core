#include "push_swap.h"

int	get_stack_lenght_a(t_stack_a *stack_a)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack_a->first_el;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	get_stack_lenght_b(t_stack_b *stack_b)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack_b->first_el;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

int	find_median_a(t_stack_a *stack_a)
{
	int	num_of_elements;

	num_of_elements = get_stack_lenght_a(stack_a);
	if (num_of_elements % 2 == 0)
		return (num_of_elements / 2);
	else
		return ((num_of_elements / 2) + 1);
}

int	find_median_b(t_stack_b *stack_b)
{
	int	num_of_elements;

	num_of_elements = get_stack_lenght_b(stack_b);
	if (num_of_elements % 2 == 0)
		return (num_of_elements / 2);
	else
		return (num_of_elements / 2 + 1);
}

void	set_index(t_stack_a *stack_a, t_stack_b *stack_b)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack_a->first_el;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
	i = 0;
	current = stack_b->first_el;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
}
