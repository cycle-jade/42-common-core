#include "so_long.h"

int	close_win(t_game *game)
{
	mlx_loop_end(game->mlx);
	clean_mlx(game);
	return (0);
}

void	ending_loop(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->img->img_ptr);
	game->img->img_ptr = NULL;
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	win_banner();
	you_win(game);
}

void	update_ps(t_game *game, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = game->player->x + x;
	next_y = game->player->y + y;
	if (game->map->data[next_y][next_x] == '1')
		return ;
	if (game->map->data[next_y][next_x] == 'c')
	{
		game->items--;
		game->map->data[next_y][next_x] = 'F';
	}
	if (game->items == 0)
		game->exit++;
	if (game->map->data[next_y][next_x] == 'e' && game->exit > 0)
		ending_loop(game);
	game->player_moves++;
	game->player->x = next_x;
	game->player->y = next_y;
}

int	key_input(int keynum, t_game *game)
{
	if (keynum == 65307)
	{
		mlx_loop_end(game->mlx);
		clean_mlx(game);
	}
	else if (keynum == 100)
		update_ps(game, 1, 0);
	else if (keynum == 97)
		update_ps(game, -1, 0);
	else if (keynum == 119)
		update_ps(game, 0, -1);
	else if (keynum == 115)
		update_ps(game, 0, 1);
	return (0);
}
