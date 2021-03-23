/*
void draw_line(t_game *game, t_axis *start_pos)
{
    float	i;
	float	j;
    t_axis pos;

	i = 0;
    pos.x = start_pos->x * MAP_SIZE;
	pos.y = start_pos->y * MAP_SIZE;
	while (i < sin(game->player.rotation_angle) * 30)
	{
		j = 0;
		while (j < cos(game->player.rotation_angle) * 30)
		{
			if ((pos.x + i < game->set.res.x) && (pos.y + j < game->set.res.y) && (pos.x + i > 0) && (pos.y + j > 0))
				my_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, MAP_PLAYER);
			j++;
		}
		i++;
	}
}*/
/*
int hit_wall(char **map, t_axis pos)
{
    if (map[pos.y][pos.x] == )
}*/
/*
void	init_player(t_game *game)
{
	game->player.pos.x = game->set.start_pos.x * MAP_SIZE;
	game->player.pos.y = game->set.start_pos.y * MAP_SIZE;
	game->player.turn_dir = 0;
	game->player.walk_dir = 0;
	game->player.rotation_angle = M_PI / 2;
	game->player.move_speed = 3.0;
	game->player.rotation_speed = 3 * (M_PI / 180);
//	game->player.radius = 3;
}
*/

/*
void    raycaster(t_game game, char **map)
{
    double dirX = -1;
    double dirY = 0;
    double planeX = 0;
    double planeY = 0.66;

	double time = 0;
	double oldTime = 0;


}