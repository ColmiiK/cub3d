#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <libft.h>
# include <math.h>

# define W_WIDTH 2000
# define W_HEIGHT 2000

# define R_WIDTH 2000 / 50
# define R_HEIGHT 2000 / 50

# define VISION 90

# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define RED 0xff0000ff
# define GRAY 0x808080ff
# define BLUE 0x0000ffff
# define PINK 0xF8A4A7ff

typedef struct s_tex
{
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
	float		p_x;
	float		p_y;
	float		p_a;
	int			m_x;
	int			m_y;
	int			width;
	int			height;

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
	float	distance_x;
	float	distance_y;
	float	ray_angle;
	float	plyer_angle;
}	t_tools;

int		ft_parse_map(t_data *data, char *str);
int		ft_extract_info(t_data *data, char **cub);
int		ft_read_cub_file(t_data *data, char *str);
int		ft_check_map(char **map);
int		ft_check_longest_line(char **map);
int		ft_inject_space(char **map);

int		ft_initialize_mlx(t_data *data);
void	ft_keyhook(void *param);
void	ft_move_minimap(t_data *data, int x, int y);
void	ft_draw_minimap(t_data *data);

int		ft_cleanup(t_data data);

void	ft_draw_background(t_data *data);
void	ft_draw_game(t_data *data);

t_tools	*vector_define(t_data *data);
void	x_wall_finder(t_data *data, t_tools **tools);
void	y_wall_finder(t_data *data, t_tools **tools);
void	igomeow(t_data *data);

#endif