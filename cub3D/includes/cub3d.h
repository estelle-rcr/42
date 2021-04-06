/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/07 01:11:27 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdarg.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "keys.h"
# include "settings.h"
# include "errors.h"

#ifndef M_PI
# define M_PI 3.14159265358979323846264338327950288
#endif

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

# define MAP_CHARSET "012NSEW"
# define PLAY_CHARSET "02NSEW"
# define DIR_CHARSET "NSEW"
# define NB_SETTINGS 8

typedef struct		s_axis
{
	float	x;
	float	y;
}					t_axis;

typedef struct		s_dblaxis
{
	double	x;
	double	y;
}					t_dblaxis;

typedef struct		s_settings
{
	int		fd;
	t_axis	res;
	t_axis	start_pos;
	char	player_dir;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*s_texture;
	int		f_color;
	int		c_color;
	char 	**map;
	int		map_width;
	int		map_height;
}					t_settings;

typedef struct		s_img_data {
	void	*img;
	char	*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img_data;


typedef struct		s_texture
{
	void	*img;
	char	*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct		s_player
{
	t_axis		pos;
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotation_left;
	int			rotation_right;
	double		move_speed;
	double		rotation_speed;
}					t_player;

typedef struct	s_ray
{
	t_dblaxis	pos;
	t_dblaxis	dir;
	t_dblaxis	plan;
	t_dblaxis	ray_dir;
	double		camerax;
	int			map_x;
	int			map_y;
	t_dblaxis	side_dist;
	t_dblaxis	delta_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			start;
	int			end;
	int			x;
	double		move_speed;
	double		rotation_speed;
	int			texture;
}				t_ray;

typedef	struct s_sprite
{
	t_dblaxis	sprite_pos;
	t_dblaxis	transform;
	double		*distance;
	double		invdet;
	double		*zbuffer;
	float				sprite_screenx;
	float				sprite_height;
	float				sprite_width;
	t_axis		sprite_start;
	t_axis		sprite_end;
}					t_sprite;

typedef struct		s_game
{
	void		*mlx;
	void		*win;
	int			save;
	float		dst_projection_plane;
	t_settings	set;
	t_img_data	img;
	t_player	player;
	t_ray		ray;
	t_sprite	sprite;
	t_texture	north_txt;
	t_texture	south_txt;
	t_texture	west_txt;
	t_texture	east_txt;
	t_texture	sprites_txt;
}					t_game;

// main
int			main(int ac, char **av);

// open_file
t_settings		*init_set(t_settings *set);
int			check_extension(char *file, char *type);
int			open_file(char *file);
int			is_whitespace(char *str);
int			read_file(char *file, t_settings *set);

//cub3d parser utils
char		**free_tab(char **tab);
int			atoi_res(const char *str);
int			check_atoi_colors(char *str);
void		free_map(char **map);

// parser
int			check_params(char **params, t_settings *set);
int			all_params(t_settings *set);
int			parse_file(char *line, t_settings *set);

// parser_RTC
int			check_resolution(char **params, t_settings *set);
int			check_textures(char **params, t_settings *set);
int			check_colors(char **params, t_settings *set);

// split_sep
char		**ft_split_whitespaces(char *str);

// handle_errors
int			print_err_msg(int error);
int			error_files(int error);
int			error_rtc(int error);
int			error_map(int error);
int			error_mlx(int error);

// minilib_utils_color
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
//int		add_shade(double distance, int trgb);
//int		get_opposite(int trgb);

// parser_cpy_map
int			is_map(char *s);
char		*ft_strdup_fill(char *s1, int len);
int 		copy_map(char *line, t_settings *set);
int			get_map(char *line, t_settings *set);

// parser_map_tabs.c
char		*replace_tabs(char *line);
char		*dup_space(char *line);
void		add_spaces(char *s, int i);

// parser_check_map
int 		is_valid_map(char **map);
int 		valid_cells(char case1, char case2);
int 		get_start_position(t_settings *set);
int			comp_null_cells(char **map, int x, int y);
int			check_map(t_settings *set);

// floodfill
int			flood_fill(char **copy_map, float pos_x, float pos_y);

// init_mlx

int			run_mlx(t_game *game);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
int			create_mlx_win(t_game *game);
int			my_mlx_new_img(void *mlx, t_img_data *img, int x, int y);
int			render(t_game *game);

// events
int			handle_keypress(int keysym, t_game *game);
int			handle_keyrelease(int keysym, t_game *game);

// exit_mlx
int			exit_game(t_game *game);

// raycasting


// raycasting_player
void	ft_move_forward_back(t_ray *ray, t_player *player, char **map)
void	ft_move_left_right(t_ray *ray, t_player *player, char **map);
void	ft_rotation_left_right(t_ray *ray, t_player *player);
void	update_player(t_game *game, t_player *player);

// raycasting init



// raycasting_setup


//raycasting_utils
void		set_axis(t_axis *point, float x, float y);
int 		is_wall(t_game *game, int axis_x, int axis_y);

// raycasting_wall


// map_display_bonus
void		draw_map(t_game *game, t_settings *set);
void 		draw_player(t_game *game);
void		draw_line(t_game *game);
int 		printable_map(t_game *game, float x, float y);
void		draw_ray(t_game *game, t_axis start, t_axis end);


#endif
