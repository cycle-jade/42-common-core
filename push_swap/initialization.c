#include "push_swap.h"

void	closing(int flag, char **argv)
{
	if (flag == 1)
		free_argv(argv);
	ft_printf("Error\n");
	exit(0);
}

bool	check_if_string_is_integer(char *str)
{
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		return (false);
	return (true);
}

bool	check_for_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	error_handling(char **argv, int flag)
{
	int	count;

	count = 1;
	while (argv[count] != NULL)
	{
		if (check_string_is_number(argv[count]) == false)
			closing(flag, argv);
		if (check_if_string_is_integer(argv[count]) == false)
			closing(flag, argv);
		if (check_for_duplicates(argv) == false)
			closing(flag, argv);
		count++;
	}
}
