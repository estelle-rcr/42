/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/03/29 23:32:21 by erecuero         ###   ########.fr       */
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

typedef struct		s_text_data
{
	void	*img;
	char	*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_text_data;

typedef struct		s_player
{
	t_axis		pos;
	double		turn_dir;
	double		walk_dir;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
	double		direction_angle;
}					t_player;

typedef struct	s_ray
{
	float	distance;
	float	angle;
	t_axis	wall_hit;
	char	wall_content;
	int		facing_down;
	int		facing_right;
	int		hit_vertical;
	int		hit_horizontal;
	int		north_wall;
	int		south_wall;
	int		west_wall;
	int		east_wall;
}				t_ray;

typedef struct		s_game
{
	void		*mlx;
	void		*win;
	t_img_data	img;
	t_text_data	north_txt;
	t_text_data	south_txt;
	t_text_data	west_txt;
	t_text_data	east_txt;
	t_text_data	sprites_txt;
	t_settings	set;
	t_player	player;
	t_ray		*rays;
	float		dst_projection_plane;
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

int			run_mlx(t_game *game, int save);
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
void		cast_all_rays(t_game *game);
double		normalize_angle(double *ray_angle);
void		find_horizontal_intercept(t_game *game, t_ray *ray);
void		find_vertical_intercept(t_game *game, t_ray *ray);
double		distance_btw_points(double x1, double y1, double x2, double y2);
void		draw_ray(t_game *game, t_ray *ray);
void	draw_ray_test(t_game *game, t_axis start, t_axis end);


// raycasting_wall
double	fishbowl(t_game *game, t_ray *ray);
void	render_wall(t_game *game);
void	draw_wall(t_game *game, t_ray *ray, double wall_height, int ray_index);
void	wall_setup(t_axis res, double wall_height, int *top_pixel, int *bottom_pixel);

// raycasting init
int			init_game(t_game *game);
void		init_ray(t_ray *ray, float ray_angle);
void		init_player(t_game *game);

// raycasting_setup
int			hit_screen(t_game *game, float x, float y);
void		draw_rect(t_game *game, t_axis pos, t_axis end, int color);
void		render_background(t_game *game);
void		update_player(t_game *game, t_player *player);


// map_display_bonus
void		draw_map(t_game *game, t_settings *set);
void 		draw_player(t_game *game);
void		draw_line(t_game *game);
int 		printable_map(t_game *game, float x, float y);
int 		hit_wall(t_game *game, int x, int y);

#endif
