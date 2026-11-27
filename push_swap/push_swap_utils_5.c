#include "push_swap.h"

void	sort_three_reverse(t_stack_a *stack_a, t_stack_b *stack_b)
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

bool	is_sorted_reverse(t_stack_a *stack_a)
{
	t_node	*current;
	t_node	*next;

	current = stack_a->first_el;
	while (current->next != NULL)
	{
		next = current->next;
		if (current->num < next->num)
			return (false);
		current = next;
	}
	return (true);
}

int	count_elements(char **argv)
{
	int	count;

	count = 0;
	while (argv[count] != NULL)
	{
		count++;
	}
	return (count);
}

void	handle_single_element(int *argc, char ***argv, int *flag)
{
	char	*temp;

	*(*argv + 1) = ft_strjoin("t ", *(*argv + 1));
	temp = *(*argv + 1);
	*argv = ft_split(*(*argv + 1), ' ');
	free(temp);
	*argc = count_elements(*argv);
	*flag = 1;
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
