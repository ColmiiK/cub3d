#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <libft.h>
# include <math.h>

# define W_WIDTH 1500
# define W_HEIGHT 1500

# define VISION 90

# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define RED 0xff0000ff
# define GRAY 0x808080ff
# define BLUE 0x0000ffff
# define PINK 0xF8A4A7ff
# define LOCKED 0x3B3B3Bff
# define UNLOCKED 0xA7A7A7ff

typedef struct s_tex
{
	mlx_texture_t	*sprite[5];
	mlx_image_t		*i_sprite[5];
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				floor;
	int				ceiling;
}	t_tex;

typedef struct s_data
{
	mlx_t		*mlx;
	t_tex		*texture;
	mlx_image_t	*minimap;
	mlx_image_t	*player;
	mlx_image_t	*game_img;
	char		**map;
	char		**cub;
	double		p_x;
	double		p_y;
	double		p_a;
	int			m_x;
	int			m_y;
	int			width;
	int			height;
	int			frame;
	bool		shooting_gun;

}	t_data;

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_tools
{
	int		vector_x;
	int		vector_y;
	t_coord	*x_cross;
	t_coord	*y_cross;
	double	distance_x;
	double	distance_y;
	double	ray_angle;
	double	plyer_angle;
}	t_tools;

int		ft_parse_map(t_data *data, char *str);
int		ft_extract_info(t_data *data, char **cub);
int		ft_read_cub_file(t_data *data, char *str);
int		ft_check_map(char **map);
int		ft_check_longest_line(char **map);
int		ft_inject_space(char **map);

int		ft_initialize_mlx(t_data *data);
void	ft_load_sprites(t_data *data);
void	ft_hook(void *param);
void	ft_mousehook(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
void	ft_move_minimap(t_data *data, double x, double y);
void	ft_draw_minimap(t_data *data);
void	ft_fill_square(int color, mlx_image_t *minimap, int x, int y);

int		ft_cleanup(t_data data);

void	ft_draw_background(t_data *data);
void	ft_draw_game(t_data *data);

//ray_defines
double	rad_convertor(double deg);
t_tools	*vector_define(t_data *data);
t_coord	*first_step_x(t_data *data, t_tools *tools);
t_coord	*first_step_y(t_data *data, t_tools *tools);
//init_raycast
int		ft_delimiter(t_data *data, t_coord *cross);
t_coord	*x_wall_finder(t_data *data, t_tools *tools);
t_coord	*y_wall_finder(t_data *data, t_tools *tools);
void	igomeow(t_data *data);

#endif