#include "so_long.h"

void	free_struct(t_game *game)
{
	free(game->img);
	free(game->map);
	free(game->player);
	exit(EXIT_FAILURE);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->height)
	{
		free(game->map->data[i]);
		i++;
	}
	free(game->map->data);
}

void	free_v2(t_game *game)
{
	free(game->img);
	free(game->foe);
	free(game->player);
	free_map(game);
	free(game->map);
	exit(EXIT_FAILURE);
}

void	clean_mlx(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->img_ptr);
	game->img->img_ptr = NULL;
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->img);
	free(game->player);
	free_map(game);
	free(game->map);
	free(game->foe);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

void	freeing_map(t_game *game)
{
	free(game->map);
	free_struct(game);
	exit(EXIT_FAILURE);
}
