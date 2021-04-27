/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:23:37 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/28 00:11:30 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# include "keys_bonus.h"
# include "settings_bonus.h"
# include "errors_bonus.h"
# include "bitmap_bonus.h"

typedef struct		s_axis
{
	int	x;
	int	y;
}					t_axis;

typedef struct		s_dblaxis
{
	double	x;
	double	y;
}					t_dblaxis;

typedef struct		s_settings
{
	int			fd;
	t_dblaxis	res;
	t_dblaxis	start_pos;
	char		player_dir;
	char		*no_txt;
	char		*so_txt;
	char		*we_txt;
	char		*ea_txt;
	char		*s_txt;
	int			f_color;
	int			c_color;
	char		**map;
	int			map_width;
	int			map_height;
}					t_settings;

typedef struct		s_img_data
{
	void			*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img_data;

typedef struct		s_text_data
{
	void			*img;
	int				*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_text_data;

typedef struct		s_texture
{
	int			txt_dir;
	double		wall_x;
	int			txt_x;
	int			txt_y;
	double		step;
	double		txt_pos;
}					t_texture;

typedef struct		s_player
{
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotation_left;
	int			rotation_right;
	double		pitch;
	float		cam_z;
}					t_player;

typedef struct		s_ray
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
}					t_ray;

typedef	struct		s_sprite
{
	int			nb;
	int			*order;
	t_dblaxis	s_pos;
	t_dblaxis	transform;
	double		*distance;
	double		inv_det;
	double		*zbuffer;
	int			s_screenx;
	int			s_height;
	int			s_width;
	t_axis		s_start;
	t_axis		s_end;
}					t_sprite;

typedef struct		s_cf_data
{
	char		*ceil_txt;
	char		*floor_txt;
	t_dblaxis	ray_dir_0;
	t_dblaxis	ray_dir_1;
	double		pos_z;
	float		row_dist;
	t_dblaxis	floor_step;
	t_dblaxis	floor;
	int			p;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
	int			is_floor;
}					t_cf_data;

typedef struct		s_map
{
	t_axis	start;
	t_axis	end;
	int		is_on;
	int		size;
}					t_map;

typedef struct		s_bonus
{
	char	*light;
	char	*food;
	char	*vault;
	char	*key_pu;
	char	*gun_pu;
	char	*gun_hud;
	char	*knife;
	char	*hud;
}					t_bonus;

typedef struct		s_game
{
	void		*mlx;
	void		*win;
	int			save;
	int			sp_nb;
	int			hud_size;
	t_settings	set;
	t_img_data	img;
	t_player	player;
	t_ray		ray;
	t_texture	wall;
	t_sprite	sprite;
	t_dblaxis	*obj;
	t_text_data	textures[NB_TEXT];
	t_cf_data	cf;
	t_map		map;
	t_bonus		adds;
}					t_game;

int					main(int ac, char **av);
t_settings			*init_set(t_settings *set);
int					check_extension(char *file, char *type);
int					open_file(char *file);
int					is_whitespace(char *str);
int					read_file(char *file, t_settings *set);
char				**free_tab(char **tab);
int					atoi_res(const char *str);
int					check_atoi_colors(char *str);
void				free_map(char **map);
int					check_params(char **params, t_settings *set);
int					all_params(t_settings *set);
int					parse_file(char *line, t_settings *set);
int					check_resolution(char **params, t_settings *set);
int					check_textures(char **params, t_settings *set);
int					check_colors(char **params, t_settings *set);
char				**ft_split_whitespaces(char *str);
int					print_err_msg(int error);
int					error_files(int error);
int					error_rtc(int error);
int					error_map(int error);
int					error_mlx(int error);
int					is_map(char *s, t_settings *set);
int					copy_map(char *line, t_settings *set);
int					get_map(char *line, t_settings *set);
int					get_start_position(t_settings *set);
char				**ft_get_file(int fd, int lvl);
int					is_valid_map(t_settings *set, char **map);
int					valid_cells(char case1, char case2);
int					valid_memory(t_settings *set, char **map, int x, int y);
int					comp_null_cells(char **map);
int					check_map(t_settings *set);
int					create_mlx_win(t_game *game);
int					my_mlx_new_img(void *mlx, t_img_data *img, int x, int y);
int					run_mlx(t_game *game);
int					handle_keypress(int keysym, t_game *game);
int					handle_keyrelease(int keysym, t_game *game);
int					cast_rays(t_game *game);
void				step_side_dist(t_game *game, t_ray *ray);
void				perform_dda_loop(t_game *game, t_ray *ray);
void				create_wall_stripes(t_game *game, t_ray *ray);
void				draw_color(t_game *game, t_ray *ray);
void				move_forward_back(t_ray *ray, t_player *player, char **map);
void				move_left_right(t_ray *ray, t_player *player, char **map);
void				rotation_left_right(t_ray *ray, t_player *player);
void				rotation_left(t_ray *ray);
int					init_game(t_game *game);
void				init_ray(t_game *game);
void				init_ray_direction(t_game *game);
void				init_texture(t_game *game);
void				init_obj(t_game *game);
int					init_sprite(t_game *game);
int					load_texture(t_game *game);
int					exit_textures(t_game *game);
void				get_addr_texture(t_game *game);
void				setup_wall_textures(t_game *game, int y);
void				setup_distance_order(t_game *game, t_ray *ray);
void				sort_distance_order(t_game *game);
void				setup_sprites(t_game *game, t_ray *ray);
void				loop_draw_sprite(t_game *game, int tex_x, int stripe, int sp_nb);
void				render_sprite(t_game *game);
int					exit_game(t_game *game);
int					exit_free_mlx_components(t_game *game);
void				exit_free_settings(t_settings *set);
int					exit_gnl(char *line, t_settings *set);
int					screenshot(t_game *game);
void				create_bmp_header(t_game *game, int fd);


// raycasting cf text
void				draw_textured_cf(t_game *game, t_ray *ray);
void				init_cf_textures(t_game *game);
void				setup_additionnal_text(t_game *game, t_ray *ray, int y);
void				setup_cf(t_game *game);

// raycasting add sprites
int					load_textures_bonus(t_game *game);
int					load_add_sprites(t_game *game, char *text, int text_nb);
int					find_sprite_nb(t_game *game, int x, int y);
int					filter_sprite_bg(int color);
int					check_sprite(t_game *game, int y);

// raycasting player
void				look_up_down(t_game *game, t_cf_data *cf);
void				move_jump_crouch(t_game *game, t_cf_data *cf);
void				handle_bonus_keypress(int keycode, t_game *game);
void				handle_bonus_keyrelease(int keycode, t_game *game);

// map_display_bonus
void				init_map(t_game *game);
void				draw_player(t_game *game);
void				draw_rect(t_game *game, t_axis pos, t_axis end, int color);
void				draw_map(t_game *game, t_settings *set);

// raycasting text
int					add_shade(double distance, int trgb);

// parser_map_tabs.c									// issues freeing
char				*replace_tabs(char *line);
char				*dup_space(char *line);
void				add_spaces(char *s, int i);

// minilib utils
int					add_shade(double distance, int trgb);
int					add_shade_cf(double distance, int trgb);
int					create_trgb(int t, int r, int g, int b);
int					hit_screen(t_game *game, int x, int y);
//void				my_mlx_pixel_put(t_img_data *img, int x, int y, int color);

// display_hud
void				draw_assets(t_game *game, int width, int height);
void				draw_hud(t_game *game, int width, int height);
//void				draw_gun(t_game *game, int width, int height);
void				draw_gun(t_game *game, int width, int height, int y);

#endif
