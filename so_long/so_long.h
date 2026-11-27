#ifndef SO_LONG_H
# define SO_LONG_H
# include "Get_Next_Line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "printf/ft_printf.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PIXEL_SIZE 64

typedef struct s_map
{
	char		**data;
	int			width;
	int			height;

}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			width;
	int			height;

}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
	int			player_counter;

	void		*img_ptr;
	int			width;
	int			height;

}				t_player;

typedef enum t_enemy_directions
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NUM_DIRECTIONS,
}				t_enemy_directions;

typedef struct s_foe
{
	int			x;
	int			y;

	void		*img_ptr;
}				t_foe;

typedef struct s_game
{
	void		*mlx;
	void		*win;

	int			items;
	int			x_exit;
	int			y_exit;
	int			num_foes;
	int			exit_counter;
	int			reachable_items;
	int			exit;
	int			player_moves;

	t_img		*img;
	t_foe		*foe;
	t_player	*player;
	t_map		*map;
}				t_game;

int				check_file_exstention(char *name);
void			check_map(char *file, t_game *game);
void			init_structs(t_game *game);
void			map_checks(t_game *game);
void			populate_map(t_game *game, char *file);
void			init_map(t_game *game);
int				key_input(int keynum, t_game *game);
int				close_win(t_game *game);
void			reder_background_items(t_game *game);
void			load_image(t_game *game, void **img_ptr, const char *file);
void			put_to_map(t_game *game, char c);
void			render_walls(t_game *game);
void			display_counter(t_game *game);
int				game_loop(t_game *game);
void			xpm_to_window(t_game *game, char *file, int x, int y);
void			win_banner(void);
char			*ft_strcat(char *dest, char *src);
char			*ft_strcpy(char *dest, char *src);
void			you_win(t_game *game);
void			you_lose(t_game *game);
void			free_struct(t_game *game);
void			free_v2(t_game *game);
void			clean_mlx(t_game *game);
void			display_foes(t_game *game);
void			player_animation(t_game *game);
void			check_map(char *file, t_game *game);
void			handle_perk(t_game *game, int x, int y, char c);
void			freeing_map(t_game *game);
int				height(int fd, t_game *game);
int				width(int fd, t_game *game);
void			lose_banner(void);

#endif
