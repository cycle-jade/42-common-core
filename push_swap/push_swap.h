#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_node
{
	long			num;
	int				index;
	int				cost;
	bool			above_median;
	bool			strike;
	void			*next;
	void			*previous;
	struct s_node	*target_node;
}					t_node;

typedef struct s_stack_a
{
	t_node			*first_el;
	t_node			*last_el;

}					t_stack_a;

typedef struct s_stack_b
{
	t_node			*first_el;
	t_node			*last_el;
}					t_stack_b;

void				pb(t_stack_a *stack_a, t_stack_b *stack_b);
void				pa(t_stack_a *stack_a, t_stack_b *stack_b);
void				ra(t_stack_a *stack_a, bool print);
void				rb(t_stack_b *stack_b, bool print);
void				rra(t_stack_a *stack_a, bool print);
void				rrb(t_stack_b *stack_b, bool print);
void				sa(t_stack_a *stack_a);
void				sb(t_stack_b *stack_b);
void				ss(t_stack_a *stack_a, t_stack_b *stack_b);
void				rr(t_stack_a *stack_a, t_stack_b *stack_b);
void				rrr(t_stack_a *stack_a, t_stack_b *stack_b);
int					get_stack_lenght_b(t_stack_b *stack_b);
int					get_stack_lenght_a(t_stack_a *stack_a);
int					find_median_b(t_stack_b *stack_b);
int					find_median_a(t_stack_a *stack_a);
void				calculate_cost(t_stack_a *stack_a, t_stack_b *stack_b,
						int median);
void				set_index(t_stack_a *stack_a, t_stack_b *stack_b);
void				calculate_cost(t_stack_a *stack_a, t_stack_b *stack_b,
						int median);
void				find_closest_a(t_stack_a *stack_a, t_stack_b *stack_b);
void				find_closest_b(t_stack_a *stack_a, t_stack_b *stack_b);
t_node				*find_min_a(t_stack_a *stack_a);
t_node				*find_max_b(t_stack_b *stack_b);
int					find_min_cost_b(t_stack_b *stack_b);
int					find_min_cost_a(t_stack_a *stack_a);
void				se_above_median_a(t_stack_a *stack_a, int median);
void				se_above_median_b(t_stack_b *stack_b, int median);
t_node				*find_max_a(t_stack_a *stack_a);
void				sort_three(t_stack_a *stack_a, t_stack_b *stack_b);
bool				is_sorted(t_stack_a *stack_a);
t_node				*get_node_from_index_a(t_stack_a *stack_a, int index);
void				algo_stack_a(t_stack_a *stack_a, t_stack_b *stack_b);
void				algo_stack_b(t_stack_a *stack_a, t_stack_b *stack_b);
void				algo_finals(t_stack_a *stack_a, t_stack_b *stack_b);
t_node				*get_node_from_index_b(t_stack_b *stack_b, int index);
void				run_through_it_a(t_stack_a *stack_a);
void				run_through_it_b(t_stack_b *stack_b);
void				sort_three_reverse(t_stack_a *stack_a, t_stack_b *stack_b);
bool				is_sorted_reverse(t_stack_a *stack_a);
int					count_elements(char **argv);
void				handle_single_element(int *argc, char ***argv, int *flag);
void				free_argv(char **argv);
void				closing(int flag, char **argv);
bool				check_if_string_is_integer(char *str);
bool				check_for_duplicates(char **argv);
void				error_handling(char **argv, int flag);
bool				check_string_is_number(char *str);
t_node				*init_node_a(t_stack_a *stack_a, t_stack_b *stack_b);
t_node				*init_node_b(t_stack_a *stack_a, t_stack_b *stack_b);
#endif
