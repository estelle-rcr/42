/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erecuero <erecuero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:13:55 by erecuero          #+#    #+#             */
/*   Updated: 2021/04/18 22:05:10 by erecuero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BONUS_H
# define BONUS_H

# include "cub3d.h"

// mettre cf_data et map dans game
#define CEIL './textures/metal.xpm'
#define	FLOOR './textures/metal.xpm'

typedef struct s_cf_data
{
	char		*ceil_txt;
	char		*floor_txt;
	t_dblaxis	ray_dir_0;
	t_dblaxis	ray_dir_1;
	float		pos_z;
	float		row_dist;
	t_dblaxis	floor_step;
	t_dblaxis	floor;
	int			p;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
	float		cam_z;
	double		pitch;
	double		pos_z;
}				t_cf_data;

typedef struct s_map
{
	t_axis	start;
	t_axis	end;
	int		is_on;
	int		size;
}				t_map;

// raycasting cf text
void	draw_textured_cf(t_game *game, t_ray *ray);
void	setup_additionnal_text(t_game *game, t_ray *ray, int i);
int		load_texture_cf(t_game *game);

// raycasting player
void	look_up_down(t_game *game, t_cf_data *cf);
void	move_jump_crouch(t_game *game, t_cf_data *cf);
void	handle_bonus_keypress(int keycode, t_game *game);
void	handle_bonus_keyrelease(int keycode, t_game *game);

// map_display_bonus
void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);
int		hit_screen(t_game *game, float x, float y);
int 	printable_map(t_game *game, float x, float y);
void	draw_player(t_game *game);
void	draw_rect(t_game *game, t_axis pos, t_axis end, int color);
void	draw_map(t_game *game, t_settings *set);

#endif
