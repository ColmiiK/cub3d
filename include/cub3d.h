#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <libft.h>

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
	mlx_t *mlx;
	t_tex *texture;
	
	char	**map;
	char	**cub;
	float		p_x;
	float		p_y;
	float		p_a;
	int		width;
	int		height;




}	t_data;

int ft_parse_map(t_data *data, char *str);
int ft_extract_info(t_data *data, char **cub);
int ft_read_cub_file(t_data *data, char *str);
int ft_check_map(char **map);
int ft_inject_space(char **map);

int ft_cleanup(t_data data);

#endif