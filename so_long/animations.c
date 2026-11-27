#include "so_long.h"

void	player_animation(t_game *game)
{
	static int	j = 1;
	void		*new_img;
	char		*num_str;
	char		filename[122];

	num_str = ft_itoa(j);
	ft_strcpy(filename, "./sprites/Pcharacter/animation");
	ft_strcat(filename, num_str);
	ft_strcat(filename, ".xpm");
	free(num_str);
	new_img = mlx_xpm_file_to_image(game->mlx, filename,
			&game->player->width, &game->player->height);
	mlx_put_image_to_window(game->mlx, game->win, new_img,
		game->player->x * PIXEL_SIZE, game->player->y * PIXEL_SIZE);
	mlx_destroy_image(game->mlx, new_img);
	if (game->player->img_ptr)
	{
		mlx_destroy_image(game->mlx, game->player->img_ptr);
		game->player->img_ptr = NULL;
	}
	j++;
	if (j == 16)
		j = 1;
}

void	display_foes(t_game *game)
{
	static int	i = 1;
	int			j;
	char		filename[122];
	void		*new_img;
	char		*num_str;

	j = 0;
	num_str = ft_itoa(i);
	ft_strcpy(filename, "./sprites/Ccharacter/animation");
	ft_strcat(filename, num_str);
	ft_strcat(filename, ".xpm");
	new_img = mlx_xpm_file_to_image(game->mlx, filename,
			&game->player->width, &game->player->height);
	while (j < game->num_foes)
	{
		mlx_put_image_to_window(game->mlx, game->win, new_img,
			game->foe[j].x * PIXEL_SIZE, game->foe[j].y * PIXEL_SIZE);
		j++;
	}
	mlx_destroy_image(game->mlx, new_img);
	i++;
	if (i == 16)
		i = 1;
	free(num_str);
}
