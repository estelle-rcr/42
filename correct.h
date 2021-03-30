

#ifndef CORRECT_H
# define CORRECT_H

// raycasting_correct
void	set_axis(t_axis *point, float x, float y);
char	is_wall_raycasting(t_game *game, t_axis next_touch);
void	init_ray(t_ray *ray, float ray_angle);
void	cast_all_rays(t_game *game);
void	find_horizontal_intercept_loop(t_game *game,
	t_ray *ray, t_axis next, t_axis step);
void	find_horizontal_intercept(t_game *game, t_ray *ray);
void	reset_ray_setting(t_ray *ray, float vertical_len, t_axis wall_found,
	char hit_content);
void	find_vertical_intercept_loop(t_game *game, t_ray *ray,
	t_axis next, t_axis step);
void	find_vertical_intercept(t_game *game, t_ray *ray);
void	init_player(t_player *player, t_settings set);
int		is_wall(t_game *game, float x, float y);
void	update_player_position(t_game *game, t_player *player);
float	distance_points(t_axis start, t_axis end);
float	degree_to_radian(float angle);

#endif