

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
	t_dblaxis	ray;
	double		camerax;
	int			map_x;
	int			map_y;
	t_dblaxis	side_distance;
	t_dblaxis	delta_distance;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
	int			line_height;
	int			start;
	int			end;
	int			x;
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
