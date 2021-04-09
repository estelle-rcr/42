/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/09 21:13:09 by erecuero         ###   ########.fr       */
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

# define MAP_CHARSET "012NSEW"
# define PLAY_CHARSET "02NSEW"
# define DIR_CHARSET "NSEW"
# define NB_SETTINGS 8

typedef struct		obj
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
	char	*no_txt;
	char	*so_txt;
	char	*we_txt;
	char	*ea_txt;
	char	*s_txt;
	int		f_color;
	int		c_color;
	char 	**map;
	int		map_width;
	int		map_height;
}					t_settings;

typedef struct		s_img_data {
	void	*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img_data;


typedef struct		s_text_data
{
	void		*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_text_data;

typedef struct		s_texture
{
	int		txt_dir;
	double	wall_x;
	int		txt_x;
	int		txt_y;
	double	step;
	double	txt_pos;
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
	t_dblaxis	plane;
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
	int			draw_start;
	int			draw_end;
	int			x;
	double		move_speed;
	double		rotation_speed;
	int			texture;
}				t_ray;

typedef	struct s_sprite
{
	int			nb;
	int			*order;
	t_dblaxis	s_pos;
	t_dblaxis	transform;
	double		*distance;
	double		inv_det;
	double		*zbuffer;
	float				s_screenx;
	float				s_height;
	float				s_width;
	t_axis		s_start;
	t_axis		s_end;
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
	t_texture	wall;
	t_sprite	sprite;
	t_dblaxis	*obj;
    t_text_data textures[5];
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

// parser_cpy_map
int			is_map(char *s);
char		*ft_strdup_fill(char *s1, int len);
int 		copy_map(char *line, t_settings *set);
int			get_map(char *line, t_settings *set);

// parser_map_tabs.c									// issues freeing
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
int			flood_fill(char **copy_map, float pos_x, float pos_y); 		// useless

// minilib_utils_color
int			create_trgb(int t, int r, int g, int b);
int			add_shade(double distance, int trgb);
/*
int			get_t(int trgb); 								// useless
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			get_opposite(int trgb);
*/

// init_mlx
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color); // useless
int			create_mlx_win(t_game *game);
int			my_mlx_new_img(void *mlx, t_img_data *img, int x, int y);
int			run_mlx(t_game *game);


// events
int			handle_keypress(int keysym, t_game *game);
int			handle_keyrelease(int keysym, t_game *game);

// raycasting
void		cast_rays(t_game *game);
void		step_side_dist(t_game *game, t_ray *ray);
void		perform_dda_loop(t_game *game, t_ray *ray);
void		create_wall_stripes(t_game *game, t_ray *ray);
void		draw_color(t_game *game, t_ray *ray);

// raycasting_player
void		move_forward_back(t_ray *ray, t_player *player, char **map)
void		move_left_right(t_ray *ray, t_player *player, char **map);
void		rotation_left_right(t_ray *ray, t_player *player);

// raycasting init
int			init_game(t_game *game);
void		init_ray(t_game *game, t_ray *ray);
void		init_ray_direction(t_settings *set, t_ray *ray);
void		init_texture(t_game *game, t_ray *ray);
void		init_sprite(t_game *game);

//raycasting_textures
//void		set_axis(t_axis *point, float x, float y);			// useless
//int 		is_wall(t_game *game, int axis_x, int axis_y);		// useless except map?
int			load_texture(t_game *game);
void		get_addr_texture(t_game *game);
void		setup_wall_textures(t_game *game, t_ray *ray);

// raycasting_sprites
void		setup_distance_order(t_game *game, t_ray *ray);
void		sort_distance_order(t_game *game);
void		setup_sprites(t_game *game, t_ray *ray, t_sprite *sprite, int i);
void		loop_draw_sprite(t_game *game, int tex_x, int stripe);
void		render_sprite(t_game *game);

// save
void		screenshot(t_game *game);

// exit_mlx
int			exit_game(t_game *game);								// must free


// map_display_bonus
void		draw_map(t_game *game, t_settings *set);
void 		draw_player(t_game *game);
void		draw_line(t_game *game);							// delete this one or draw_ray
int 		printable_map(t_game *game, float x, float y);
void		draw_ray(t_game *game, t_axis start, t_axis end);

#endif
