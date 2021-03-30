
#include "cub3d.h"

void	set_axis(t_axis *point, float x, float y)
{
	point->x = x;
	point->y = y;
}

char	is_wall_raycasting(t_game *game, t_axis next_touch)
{
	int			index_x;
	int			index_y;
	char		**map;
	t_axis	res;

	map = game->set.map;
	res = game->set.res;
	index_x = floor(next_touch.x);
	index_y = floor(next_touch.y);
	if (index_x < 0 || index_y < 0
		|| index_x >= res.x - 1 || index_y >= res.y - 1)
		return ('1');
	else
		return (map[index_y][index_x]);
}

void	init_ray(t_ray *ray, float ray_angle)
{
	ray->angle = ray_angle;
	set_axis(&ray->wall_hit, 0, 0);
	ray->distance = 0;
	ray->facing_down = 0;
	ray->facing_left = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		ray->facing_down = 1;
	if (ray_angle > (M_PI * 0.5) && ray_angle < (1.5 * M_PI))
		ray->facing_left = 1;
	ray->north_wall = 0;
	ray->south_wall = 0;
	ray->west_wall = 0;
	ray->east_wall = 0;
	ray->wall_content = '1';
	ray->hit_vertical = 0;
}

void	cast_all_rays(t_game *game)
{
	double	ray_angle;
	int		i;
	int		nb_column;

	i = -1;
	nb_column = game->set.res.x;
	while (++i < nb_column)
	{
		ray_angle = game->player.rotation_angle
			+ atan((i - (nb_column / 2)) / game->dst_projection_plane);
		init_ray(&game->rays[i], normalize_angle(&ray_angle));
		find_horizontal_intercept(game, &game->rays[i]);
		find_vertical_intercept(game, &game->rays[i]);
	}
}

void	find_horizontal_intercept_loop(t_game *game,
	t_ray *ray, t_axis next, t_axis step)
{
	t_axis	next_touch;
	float	offset_facing_up;
	char	wall_content;

	offset_facing_up = 0.0;
	if (!ray->facing_down)
		offset_facing_up = 1.0;
	while (next.x >= 0 && next.x < game->set.res.x
		&& next.y >= 0 && next.y < game->set.res.y)
	{
		set_axis(&next_touch, next.x, next.y - offset_facing_up);
		wall_content = is_wall_raycasting(game, next_touch);
		if (wall_content == '1' || wall_content == ' ')
		{
			set_axis(&ray->wall_hit, next.x, next.y);
			ray->distance = distance_points(game->player.pos,
				ray->wall_hit);
			ray->wall_content = wall_content;
			ray->north_wall = !offset_facing_up;
			ray->south_wall = !ray->north_wall;
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}

void	find_horizontal_intercept(t_game *game, t_ray *ray)
{
	t_axis	first;
	t_axis	step;

	first.y = floor(game->player.pos.y);
	if (ray->facing_down)
		first.y += 1;
	first.x = game->player.pos.x
		+ ((first.y - game->player.pos.y) / tan(ray->angle));
	step.y = 1;
	if (!ray->facing_down)
		step.y *= -1;
	step.x = 1 / tan(ray->angle);
	if ((ray->facing_left && step.x > 0) || (!ray->facing_left && step.x < 0))
		step.x *= -1;
	find_horizontal_intercept_loop(game, ray, first, step);
}

void	reset_ray_setting(t_ray *ray, float vertical_len, t_axis wall_found,
	char hit_content)
{
	ray->distance = vertical_len;
	set_axis(&ray->wall_hit, wall_found.x, wall_found.y);
	ray->wall_content = hit_content;
	ray->north_wall = 0;
	ray->south_wall = 0;
	ray->west_wall = !ray->facing_left;
	ray->east_wall = !ray->west_wall;
	ray->hit_vertical = 1;
}

void	find_vertical_intercept_loop(t_game *game, t_ray *ray,
	t_axis next, t_axis step)
{
	t_axis	next_touch;
	float	offset_facing_left;
	char	wall_content;
	float	vertical_len;

	offset_facing_left = 0.0;
	if (ray->facing_left)
		offset_facing_left = 1.0;
	while (next.x >= 0 && next.x < game->set.res.x
		&& next.y >= 0 && next.y < game->set.res.y)
	{
		set_axis(&next_touch, next.x - offset_facing_left, next.y);
		wall_content = is_wall_raycasting(game, next_touch);
		if (wall_content == '1' || wall_content == ' ')
		{
			vertical_len = distance_points(game->player.pos, next);
			if (vertical_len < ray->distance || ray->distance == 0)
				reset_ray_setting(ray, vertical_len, next, wall_content);
			break ;
		}
		set_axis(&next, next.x + step.x, next.y + step.y);
	}
}

void	find_vertical_intercept(t_game *game, t_ray *ray)
{
	t_axis	first;
	t_axis step;

	first.x = floor(game->player.pos.x);
	if (!ray->facing_left)
		first.x += 1;
	first.y = game->player.pos.y
		+ ((first.x - game->player.pos.x) * tan(ray->angle));
	step.x = 1;
	if (ray->facing_left)
		step.x *= -1;
	step.y = tan(ray->angle);
	if ((!ray->facing_down && step.y > 0) || (ray->facing_down && step.y < 0))
		step.y *= -1;
	find_vertical_intercept_loop(game, ray, first, step);
}

void	init_player(t_player *player, t_settings set)
{
	t_axis	start;
	char		card;
	float		angle;

	start = set.start_pos;
	card = set.player_dir;
	set_axis(&player->pos, start.x + 0.5,
		start.y + 0.5);
	player->turn_dir = 0;
	player->walk_dir = 0;
	if (card == 'S')
		angle = M_PI / 2.0;
	else if (card == 'N')
		angle = (3.0 * M_PI) / 2.0;
	else if (card == 'E')
		angle = 0;
	else
		angle = M_PI;
	player->rotation_angle = angle;
	player->move_speed = MOVE_SPEED;
	player->rotation_speed = ROTATION_SPEED * (M_PI / 180);
	// set.res.x * MOVE_SPEED / MY_SCREEN_WIDTH
	// ((set.res.x * ROTATION_SPEED / MY_SCREEN_WIDTH) * M_PI) / 180
	player->direction_angle = 0;
}

int		is_wall(t_game *game, float x, float y)
{
	int			index_x;
	int			index_y;
	char		**map;
	t_axis	res;

	map = game->set.map;
	res = game->set.res;
	index_x = floor(x);
	index_y = floor(y);
	if (index_x < 0 || index_y < 0
		|| index_x >= res.x || index_y >= res.y)
		return (1);
	return (map[index_y][index_x] != '0');
}

void	update_player_position(t_game *game, t_player *player)
{
	float			move_step;
	t_axis		next_position;
	float			xstep;
	float			ystep;

	player->rotation_angle += player->turn_dir
									* player->rotation_speed;
	move_step = player->walk_dir * player->move_speed;
	xstep = cos(player->rotation_angle + player->direction_angle);
	ystep = sin(player->rotation_angle + player->direction_angle);
	next_position.x = player->pos.x
		+ (xstep * move_step);
	next_position.y = player->pos.y
		+ (ystep * move_step);
	if (!is_wall(game, next_position.x, next_position.y))
	{
		player->pos.x = next_position.x;
		player->pos.y = next_position.y;
	}
	player->rotation_angle = normalize_angle(&player->rotation_angle);
}

float	distance_points(t_axis start, t_axis end)
{
	float	distance;
	float	dx;
	float	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	distance = sqrt(pow(dx, 2) + pow(dy, 2));
	return (distance);
}

float	degree_to_radian(float angle)
{
	float radian;

	radian = (M_PI * angle) / 180;
	return (radian);
}
