#include "push_swap.h"

void	populate_nodes_inverted(t_node *node, char **argv, int argc,
		t_stack_a *stack_a)
{
	int	i;
	int	p;

	node[0].next = &node[1];
	node[0].previous = NULL;
	node[0].num = ft_atoi(argv[argc - 1]);
	i = 1;
	p = argc - 2;
	while (i < argc - 1)
	{
		node[i].next = &node[i + 1];
		node[i].previous = &node[i - 1];
		node[i].num = ft_atoi(argv[p]);
		p--;
		i++;
	}
	node[argc - 2].next = NULL;
	node[argc - 2].previous = &node[argc - 3];
	node[argc - 2].num = ft_atoi(argv[1]);
	stack_a->first_el = &node[0];
	stack_a->last_el = &node[argc - 2];
}

void	init(int argc, t_stack_a *stack_a, t_stack_b *stack_b, t_node **node)
{
	int	i;

	i = 0;
	stack_a->first_el = NULL;
	stack_b->first_el = NULL;
	stack_a->last_el = NULL;
	stack_b->last_el = NULL;
	*node = malloc(sizeof(t_node) * (argc - 1));
	while (i < argc - 1)
	{
		(*node)[i].next = NULL;
		(*node)[i].previous = NULL;
		(*node)[i].num = 0;
		(*node)[i].index = 0;
		(*node)[i].cost = 0;
		(*node)[i].above_median = false;
		(*node)[i].target_node = NULL;
		(*node)[i].strike = false;
		i++;
	}
}

bool	check_string_is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

void	initialize_and_process(int argc, char *argv[], int flag)
{
	t_stack_a	stack_a;
	t_stack_b	stack_b;
	t_node		*node;

	error_handling(argv, flag);
	init(argc, &stack_a, &stack_b, &node);
	populate_nodes_inverted(node, argv, argc, &stack_a);
	set_index(&stack_a, &stack_b);
	if (flag == 1)
		free_argv(argv);
	if (get_stack_lenght_a(&stack_a) == 1)
	{
		free(node);
		return ;
	}
	if (get_stack_lenght_a(&stack_a) == 2 && !is_sorted_reverse(&stack_a))
		sa(&stack_a);
	else if (get_stack_lenght_a(&stack_a) == 3 && !is_sorted_reverse(&stack_a))
		sort_three_reverse(&stack_a, &stack_b);
	else if (!is_sorted_reverse(&stack_a))
		algo_stack_a(&stack_a, &stack_b);
	free(node);
}

int	main(int argc, char *argv[])
{
	int	flag;

	flag = 0;
	if (argc >= 2)
	{
		if (argv[1][0] == '\0')
		{
			ft_printf("\n");
			exit(0);
		}
		if (argv[1][0] == ' ')
			closing(0, argv);
		if (argc == 2)
			handle_single_element(&argc, &argv, &flag);
		initialize_and_process(argc, argv, flag);
	}
	return (0);
}
