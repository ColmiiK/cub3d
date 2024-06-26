/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:53 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 17:18:27 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <libft.h>
# include <math.h>

# define W_WIDTH 1280
# define W_HEIGHT 960

# define VISION 60

# define BLACK 0x000000ff
# define WHITE 0xffffffff
# define RED 0xff0000ff
# define GRAY 0x808080ff
# define BLUE 0x0000ffff
# define PINK 0xF8A4A7ff
# define TRANSPARENT 0x00000000

typedef struct s_tex
{
	mlx_texture_t	*sprite[12];
	mlx_image_t		*i_sprite[12];
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	int				floor;
	int				ceiling;
}	t_tex;

typedef struct s_data
{
	mlx_t			*mlx;
	t_tex			*texture;
	mlx_image_t		*minimap;
	mlx_image_t		*player;
	mlx_image_t		*game_img;
	mlx_image_t		*wall;
	mlx_image_t		*line;
	mlx_image_t		*debug_info;
	char			**map;
	char			**cub;
	double			p_x;
	double			p_y;
	double			p_a;
	double			angle;
	int				m_x;
	int				m_y;
	int				width;
	int				height;
	int				frame;
	bool			shooting_gun;
	bool			debug_flag;

}	t_data;

typedef struct s_coord
{
	double			x;
	double			y;
}	t_coord;

typedef struct s_tools
{
	mlx_texture_t	*orientation;
	int				wall_size;
	int				vector_x;
	int				vector_y;
	t_coord			*x_cross;
	t_coord			*y_cross;
	double			distance_x;
	double			distance_y;
	double			draw_cross;
	int				flag;
}	t_tools;

int		ft_parse_map(t_data *data, char *str);
int		ft_extract_info(t_data *data, char **cub);
int		ft_read_cub_file(t_data *data, char *str);
int		ft_check_map(char **map);
int		ft_check_longest_line(char **map);
int		ft_inject_space(char **map);
int		ft_extract_sprites(t_data *data);
int		ft_correct_division(int i, char **cub, t_data *data);
int		ft_return_split_one(t_data *data);

int		ft_initialize_mlx(t_data *data);
void	ft_load_sprites(t_data *data);
void	ft_hook(void *param);
void	ft_mousehook(mouse_key_t button, action_t action,
			modifier_key_t mods, void *param);
void	ft_keyhook(mlx_key_data_t keydata, void *param);
void	ft_player_movement(t_data *data);
void	ft_draw_minimap(t_data *data);
void	ft_fill_square(int color, mlx_image_t *minimap, int x, int y);

void	ft_cleanup(t_data data);

void	ft_draw_background(t_data *data);
void	ft_draw_game(t_data *data);

//				RAYCASTING
//first_step
t_coord	*first_step_x(t_data *data, t_tools *tools);
t_coord	*first_step_y(t_data *data, t_tools *tools);

//init_raycast
t_coord	*x_wall_finder(t_data *data, t_tools *tools);
t_coord	*y_wall_finder(t_data *data, t_tools *tools);
t_tools	*wall_distance(t_data *data);

//ray_defines
void	define_orientation_1(t_tools *tools, t_data *data);
void	define_orientation_2(t_tools *tools, t_data *data);
double	x_distance(t_data *data);
double	y_distance(t_data *data);
t_tools	*vector_define(t_data *data);

//ray_utils
double	rad_convertor(double deg);
int		ft_delimiter(t_data *data, t_coord *cross);

//raycast_loop
void	ray_loop(t_data *data);

//texture.c
int		ft_paint_txt(mlx_texture_t *tex, double draw_cross,
			int y, t_tools *tools);
#endif