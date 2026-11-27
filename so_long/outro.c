#include "so_long.h"

void	you_win(t_game *game)
{
	free(game->mlx);
	game->mlx = NULL;
	game->win = NULL;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 360, 358, "Outro");
	game->img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./loss_win/won.xpm",
			&game->img->width, &game->img->height);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
	sleep(5);
	clean_mlx(game);
}

void	you_lose(t_game *game)
{
	free(game->mlx);
	game->mlx = NULL;
	game->win = NULL;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 360, 358, "Outro");
	game->img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./loss_win/lost.xpm",
			&game->img->width, &game->img->height);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
	sleep(5);
	clean_mlx(game);
}

void	win_banner(void)
{
	ft_printf("█   █ ████ █  █  █       █ ████ ██  █\n");
	ft_printf(" █ █  █  █ █  █   █     █  █  █ █ █ █\n");
	ft_printf("  █   █  █ █  █    █ █ █   █  █ █  ██\n");
	ft_printf("  █   ████ ████     █ █    ████ █   █\n");
}

void	lose_banner(void)
{
	ft_printf("█   █ ████ █  █  █    ████  ████  ████\n");
	ft_printf(" █ █  █  █ █  █  █    █  █  █     █   \n");
	ft_printf("  █   █  █ █  █  █    █  █  ████  ████\n");
	ft_printf("  █   █  █ █  █  █    █  █     █  █   \n");
	ft_printf("  █   ████ ████  ████ ████  ████  ████\n");
}
