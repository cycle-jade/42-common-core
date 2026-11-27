#include "so_long.h"

void	check_lose(t_game *game)
{
	int	j;

	j = 0;
	while (j < game->num_foes)
	{
		if (game->player->x == game->foe[j].x
			&& game->player->y == game->foe[j].y)
		{
			mlx_destroy_image(game->mlx, game->img->img_ptr);
			game->img->img_ptr = NULL;
			mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			mlx_loop_end(game->mlx);
			lose_banner();
			you_lose(game);
		}
		j++;
	}
}

void	calculate_np(int *next_x, int *next_y, t_enemy_directions dir)
{
	if (dir == LEFT)
		(*next_x) -= 1;
	else if (dir == RIGHT)
		(*next_x) += 1;
	else if (dir == UP)
		(*next_y) -= 1;
	else if (dir == DOWN)
		(*next_y) += 1;
}

void	update_ep(t_game *game)
{
	int					i;
	int					next_x;
	int					next_y;
	t_enemy_directions	dir;

	i = 0;
	while (i < game->num_foes)
	{
		dir = (t_enemy_directions)(rand() % NUM_DIRECTIONS);
		next_x = game->foe[i].x;
		next_y = game->foe[i].y;
		calculate_np(&next_x, &next_y, dir);
		if (game->map->data[next_y][next_x] != '1' &&
		(game->map->data[next_y][next_x] != 'c' &&
		(game->map->data[next_y][next_x] != 'e')))
		{
			game->foe[i].x = next_x;
			game->foe[i].y = next_y;
		}
		i++;
	}
}

int	game_loop(t_game *game)
{
	static int	i = 0;

	check_lose(game);
	reder_background_items(game);
	render_walls(game);
	player_animation(game);
	display_counter(game);
	display_foes(game);
	mlx_do_sync(game->mlx);
	usleep(69000);
	if (i == 0)
		update_ep(game);
	i = (i + 1) % 3;
	return (1);
}
