#include "so_long.h"

void	flood_fill(char **tab, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map->width - 1 || y >= game->map->height
		- 1 || tab[y][x] == 'F')
	{
		return ;
	}
	if (tab[y][x] == 'e' || tab[y][x] == 'c' || tab[y][x] == '1'
		|| tab[y][x] == 'N')
		return ;
	if (tab[y][x] == '0' || tab[y][x] == 'P')
		tab[y][x] = 'N';
	if (tab[y][x] == 'C')
	{
		game->reachable_items++;
		tab[y][x] = 'c';
	}
	if (tab[y][x] == 'E')
	{
		game->exit++;
		tab[y][x] = 'e';
	}
	flood_fill(tab, game, x - 1, y);
	flood_fill(tab, game, x + 1, y);
	flood_fill(tab, game, x, y - 1);
	flood_fill(tab, game, x, y + 1);
}

void	first_last(char *c, t_game *game)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		if (c[i] != '1')
		{
			ft_printf("Map is not covered in walls - \n %c", c[i]);
			free_v2(game);
		}
		i++;
	}
}

void	walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		if (game->map->data[i][0] != '1' || game->map->data[i][game->map->width
			- 1] != '1')
		{
			ft_printf("Map is not covered in walls\n");
			free_v2(game);
		}
		if (i == 0 || i == game->map->height - 1)
		{
			first_last(game->map->data[i], game);
		}
		i++;
	}
}

void	rest_of_checks(t_game *game)
{
	flood_fill(game->map->data, game, game->player->x, game->player->y);
	if (game->reachable_items < game->items)
	{
		ft_printf("MAP INVALID: NOT ALL ITEMS ARE REACHABLE %d || %d",
			game->items, game->reachable_items);
		free_v2(game);
	}
	else if (game->exit == 0)
	{
		ft_printf("MAP INVALID: EXIT IS NOT REACHABLE");
		free_v2(game);
	}
	game->exit = 0;
}

void	map_checks(t_game *game)
{
	walls(game);
	if (game->exit_counter > 1 || game->exit_counter < 1)
	{
		ft_printf("Map Invalid: TOO MANY OR NO EXITS\n %d", game->exit_counter);
		free_v2(game);
	}
	if (game->player->player_counter > 1 || game->player->player_counter < 1)
	{
		ft_printf("Map is Invalid: TOO MANY OR NO PLAYERS\n%d",
			game->player->player_counter);
		free_v2(game);
	}
	if (game->items < 1)
	{
		ft_printf("Map is Invalid: AT LEAST 1 ITEM NEEDED\n %d", game->items);
		free_v2(game);
	}
	rest_of_checks(game);
}
