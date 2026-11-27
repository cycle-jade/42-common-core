#include "so_long.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*temp_dest;

	temp_dest = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (temp_dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	display_intro(t_game *game)
{
	char	filename[112];
	char	*num_str;
	int		i;
	void	*img_ptr;

	i = 0;
	game->win = mlx_new_window(game->mlx, 360, 358, "Intro");
	while (i < 121)
	{
		i++;
		num_str = ft_itoa(i);
		ft_strcpy(filename, "./introXPM/intro");
		ft_strcat(filename, num_str);
		ft_strcat(filename, ".xpm");
		free(num_str);
		img_ptr = mlx_xpm_file_to_image(game->mlx, filename, &game->img->width,
				&game->img->height);
		mlx_put_image_to_window(game->mlx, game->win, img_ptr, 0, 0);
		mlx_destroy_image(game->mlx, img_ptr);
		usleep(8500);
	}
	usleep(30000);
	mlx_destroy_window(game->mlx, game->win);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2)
	{
		init_structs(&game);
		check_map(argv[1], &game);
		init_map(&game);
		populate_map(&game, argv[1]);
		map_checks(&game);
		game.mlx = mlx_init();
		display_intro(&game);
		game.win = mlx_new_window(game.mlx, game.map->width * PIXEL_SIZE,
				game.map->height * PIXEL_SIZE, "So_Long");
		mlx_key_hook(game.win, key_input, &game);
		mlx_hook(game.win, 17, 0, close_win, &game);
		reder_background_items(&game);
		put_to_map(&game, 'c');
		render_walls(&game);
		display_counter(&game);
		mlx_loop_hook(game.mlx, (void *)game_loop, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
