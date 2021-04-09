
#ifndef M_PI
# define M_PI 3.14159265358979323846264338327950288
#endif

#define degToRad(angleInDegrees) ((angleInDegrees) * M_PI / 180.0)
#define radToDeg(angleInRadians) ((angleInRadians) * 180.0 / M_PI)

typedef struct		obj
{
	float	x;
	float	y;
}					t_axis;

typedef struct		s_player
{
	t_axis		pos;
	double		turn_dir;
	double		walk_dir;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
	double		direction_angle;
	double		right;
	double		left;
}					t_player;

typedef struct	s_ray
{
	float	distance;
	float	angle;
	t_axis	wall_hit;
	char	wall_content;
	int		facing_down;
	int		facing_left;
	int		hit_vertical;
	int		hit_horizontal;
	int		north_wall;
	int		south_wall;
	int		west_wall;
	int		east_wall;
	double	next_x;
	double	next_y;
}				t_ray;

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

typedef	struct s_sprite
{
	t_dblaxis	s_pos;
	t_dblaxis	transform;
	double		*distance;
	double		invdet;
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
	t_axis		screen_size;
	t_img_data	img;
	t_player	player;
	t_ray		*rays;
	t_text_data	north_txt;
	t_text_data	south_txt;
	t_text_data	west_txt;
	t_text_data	east_txt;
	t_text_data	sprites_txt;
}					t_game;

// raycasting
void		cast_all_rays(t_game *game);
void		find_horizontal_intercept(t_game *game, t_ray *ray);
void	horizontal_loop(t_game *game, t_ray *ray, t_axis intercept, t_axis step);
void	vertical_loop(t_game *game, t_ray *ray, t_axis next, t_axis step);
void	find_vertical_intercept(t_game *game, t_ray *ray);

// raycasting init
int			init_game(t_game *game);
void		init_ray(t_ray *ray, float ray_angle);
void		init_player(t_game *game);

// raycasting_setup
int			hit_screen(t_game *game, float x, float y);
void		draw_rect(t_game *game, t_axis pos, t_axis end, int color);
void		render_background(t_game *game);
int 		hit_wall(t_game *game, int x, int y);
void		update_player(t_game *game, t_player *player);

//raycasting_utils
int 		is_wall(t_game *game, int x, int y);
double		normalize_angle(double *ray_angle);
double		distance_btw_points(double x1, double y1, double x2, double y2);
void		set_axis(t_axis *point, float x, float y);

// raycasting_wall
double		fishbowl(t_game *game, t_ray *ray);
void		render_wall(t_game *game);
void		draw_wall(t_game *game, t_ray *ray, double wall_height, int ray_index);
void		wall_setup(t_axis res, double wall_height, int *top_pixel, int *bottom_pixel);
