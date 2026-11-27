#include "so_long.h"

int	check_foe(t_game *game, int x, int y)
{
	int	j;

	j = 0;
	while (j < game->num_foes)
	{
		if (x == game->foe[j].x && y == game->foe[j].y)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	put_to_map(t_game *game, char c)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->data[y][x] == c && (game->player->x != x
					|| game->player->y != y) && check_foe(game, x, y) != 1)
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->img->img_ptr, x * PIXEL_SIZE, y * PIXEL_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	xpm_to_window(t_game *game, char *file, int x, int y)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image(game->mlx, file, &game->img->width,
			&game->img->height);
	mlx_put_image_to_window(game->mlx, game->win, img_ptr, x * PIXEL_SIZE, y
		* PIXEL_SIZE);
	mlx_destroy_image(game->mlx, img_ptr);
}

void	load_image(t_game *game, void **img_ptr, const char *file)
{
	if (*img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx, *img_ptr);
		*img_ptr = NULL;
	}
	*img_ptr = mlx_xpm_file_to_image(game->mlx, (char *)file, &game->img->width,
			&game->img->height);
}

void	reder_background_items(t_game *game)
{
	load_image(game, &game->img->img_ptr, "./sprites/cd.xpm");
	put_to_map(game, 'F');
	put_to_map(game, '0');
	put_to_map(game, 'N');
	if (game->exit == 0)
	{
		put_to_map(game, 'e');
	}
	load_image(game, &game->img->img_ptr, "./sprites/collectible.xpm");
	put_to_map(game, 'c');
	load_image(game, &game->img->img_ptr, "./sprites/Exit.xpm");
	if (game->exit > 0)
	{
		put_to_map(game, 'e');
	}
	load_image(game, &game->img->img_ptr, "./sprites/cd.xpm");
}
