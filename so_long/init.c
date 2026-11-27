#include "so_long.h"

void	init_vars(t_game *game)
{
	game->exit_counter = 0;
	game->num_foes = 0;
	game->x_exit = 0;
	game->y_exit = 0;
	game->items = 0;
	game->exit = 0;
	game->reachable_items = 0;
	game->player->player_counter = 0;
	game->player_moves = 0;
	game->player->x = 0;
	game->player->y = 0;
	game->player->width = 0;
	game->player->height = 0;
	game->img->height = 0;
	game->img->width = 0;
	game->map->height = 0;
	game->player->img_ptr = NULL;
	game->img->img_ptr = NULL;
	game->mlx = NULL;
	game->win = NULL;
	game->foe = NULL;
}

int	width(int fd, t_game *game)
{
	int		len;
	char	*c;

	len = 0;
	c = 0;
	c = get_next_line(fd);
	if (c == NULL)
	{
		ft_printf("The file is empty\n");
		end_it(fd);
		free_struct(game);
		free(c);
	}
	while (c[len] != '\0')
		len++;
	free(c);
	return (len - 1);
}

int	height(int fd, t_game *game)
{
	int		lines;
	char	*line;
	int		current_size;

	current_size = 0;
	lines = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		while (line[current_size] != '\n' && line[current_size] != '\0')
			current_size++;
		if ((current_size) != game->map->width)
		{
			ft_printf("Map is incorrect\n", current_size);
			free(line);
			end_it(fd);
			free_struct(game);
		}
		current_size = 0;
		lines++;
		free(line);
	}
	return (lines);
}

int	check_file_exstention(char *name)
{
	while (*name != '\0')
		name++;
	if ((name[-4] == '.' && name[-3] == 'b'
			&& (name[-2] == 'e' && name[-1] == 'r')))
		return (1);
	return (0);
}

void	init_structs(t_game *game)
{
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		free(game->map);
		ft_printf("failed map allocation");
		exit(EXIT_FAILURE);
	}
	game->img = malloc(sizeof(t_img));
	if (!game->img)
	{
		free(game->img);
		free(game->map);
		ft_printf("failed img allocation");
		exit(EXIT_FAILURE);
	}
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		free(game->img);
		free(game->map);
		free(game->player);
		ft_printf("failed player allocation");
		exit(EXIT_FAILURE);
	}
	init_vars(game);
}
