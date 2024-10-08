/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bherranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:07:34 by bherranz          #+#    #+#             */
/*   Updated: 2024/06/19 12:07:36 by bherranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define TILE_S 81

//Images paths
# define COIN_IMG "textures/coin.xpm"
# define EXIT_IMG "textures/exit.xpm"
# define WALL_IMG "textures/wall.xpm"
# define GROUND_IMG "textures/ground.xpm"
//Hinata paths
# define DOWN0 "textures/player/tile000.xpm"
# define DOWN1 "textures/player/tile001.xpm"
# define DOWN2 "textures/player/tile002.xpm"
# define LEFT0 "textures/player/tile003.xpm"
# define LEFT1 "textures/player/tile004.xpm"
# define LEFT2 "textures/player/tile005.xpm"
# define RIGHT0 "textures/player/tile006.xpm"
# define RIGHT1 "textures/player/tile007.xpm"
# define RIGHT2 "textures/player/tile008.xpm"
# define UP0 "textures/player/tile009.xpm"
# define UP1 "textures/player/tile010.xpm"
# define UP2 "textures/player/tile011.xpm"

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_image
{
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	size_t	width;
	size_t	height;
	t_image	player[4][3];
	t_image	coin;
	t_image	exit;
	t_image	wall;
	t_image	ground;
}	t_mlx;

typedef struct s_game
{
	char	**map;
	int		coins;
	size_t	movements;
	t_mlx	mlx;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
	char	*dir;
}	t_game;

//mlx
void	start_mlx(t_mlx *mlx, t_game *game);
void	close_mlx(t_mlx *mlx);
int		keypress(int keysym, t_game *game);
int		destroy(void *param);

//image utils
void	init_images(t_mlx *mlx, t_game *game);
void	free_images(t_mlx *mlx);

//draw
void	draw_tile(t_mlx *mlx, void *img, int x, int y);
int		draw_map(t_game *game);
void	draw(t_game *game, int i, int j);
int		draw_player(t_game *game);

//move
void	move_player(t_game *game, int x, int y, char *dir);

//input control + check map
int		check_map(t_game *game);
void	print_error(char *msg, char function, t_game *game);
void	is_playable(char **map, t_game *game);
void	is_valid(char **map, t_game *game);
void	check_chars(t_game *game, char **map);
void	check_walls(char **map, t_game *game);
void	is_rectangular(char **map, t_game *game);

//utils
void	end_game(t_game *game, int error);
void	free_str_array(char **str);
void	print_map(char **map);
int		count_coins(char **map);
char	**copy_map(char **map);
size_t	ft_strlen_array(char **str);
void	fill(char **map, int x, int y);

//gnl
char	*read_buffer(int fd, char *buffer);
char	*new_line(char *buffer);
char	*to_be_continued(char *buffer, char *line);
char	*get_next_line(int fd);
size_t	ft_strleng(const char *s);
void	*ft_callocg(size_t count, size_t size);
char	*ft_strchrg(const char *s, int c);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_substrg(char *s, unsigned int start, size_t sub_len);

#endif
