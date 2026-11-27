#include "so_long.h"

void	allocate_foes(t_game *game, int x, int y)
{
	t_foe	*new_foe;
	int		i;

	i = 0;
	new_foe = malloc(sizeof(t_foe) * (game->num_foes + 1));
	if (!new_foe)
	{
		free_v2(game);
		exit(EXIT_FAILURE);
	}
	while (i < game->num_foes)
	{
		new_foe[i] = game->foe[i];
		i++;
	}
	game->num_foes++;
	if (game->foe)
		free(game->foe);
	game->foe = new_foe;
	game->foe[game->num_foes - 1].x = x;
	game->foe[game->num_foes - 1].y = y;
}

void	handle_perk(t_game *game, int x, int y, char c)
{
	if (c == 'P')
	{
		game->player->x = x;
		game->player->y = y;
		game->player->player_counter++;
	}
	else if (c == 'C')
	{
		game->items++;
	}
	else if (c == 'E')
	{
		game->x_exit = x;
		game->y_exit = y;
		game->exit_counter++;
	}
	else if (c == 'F')
	{
		allocate_foes(game, x, y);
	}
}

void	init_map(t_game *game)
{
	int	y;

	y = 0;
	game->map->data = (char **)malloc(sizeof(char *) * (game->map->height));
	if (game->map->data == NULL)
	{
		freeing_map(game);
	}
	while (y < game->map->height)
	{
		game->map->data[y] = NULL;
		game->map->data[y] = (char *)malloc((game->map->width + 1)
				* sizeof(char));
		ft_bzero(game->map->data[y], game->map->width + 1);
		if (!game->map->data[y])
		{
			while (y-- >= 0)
			{
				free(game->map->data[y]);
			}
			freeing_map(game);
		}
		y++;
	}
}

void	populate_map(t_game *game, char *file)
{
	int		fd;
	char	c;
	int		y;
	int		x;

	x = 0;
	y = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			x = 0;
			y++;
			continue ;
		}
		handle_perk(game, x, y, c);
		game->map->data[y][x] = c;
		x++;
	}
	close(fd);
}

void	check_map(char *file, t_game *game)
{
	int	fd;

	fd = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || !check_file_exstention(file))
	{
		ft_printf("Map error\n");
		free_struct(game);
	}
	game->map->width = width(fd, game);
	game->map->height = height(fd, game);
	if (game->map->width == game->map->height)
	{
		ft_printf("Map is not a rectangle\n");
		free_struct(game);
	}
	close(fd);
}
