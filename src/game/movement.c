#include <cub3d.h>

static int ft_check_collisions(t_data *data, double *fx, double *fy)
{
	if (data->map[(int)(data->p_y + (*fy / 3))][(int)data->p_x] == '1'
		|| data->map[(int)(data->p_y + (*fy / 3))][(int)data->p_x] == ' ')
	{
		*fy = 0.0;
		return (1);
	}
	if (data->map[(int)data->p_y][(int)(data->p_x + (*fx / 3))] == '1'
		|| data->map[(int)data->p_y][(int)(data->p_x + (*fx / 3))] == ' ')
	{
		*fx = 0.0;
		return (1);
	}
	return (0);
}

static void	ft_move_minimap(t_data *data, double dx, double dy)
{
	static double	fx = 0.0;
	static double	fy = 0.0;
	int				ix;
	int				iy;

	if (ft_check_collisions(data, &fx, &fy))
		return ;
	fx += dx;
	fy += dy;
	ix = (int)fx;
	iy = (int)fy;
	if (ix != 0)
	{
		data->p_x += ix / (W_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].x -= ix;
		fx -= ix;
	}
	if (iy != 0)
	{
		data->p_y += iy / (W_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].y -= iy;
		fy -= iy;
	}
}

void	ft_player_movement(t_data *data)
{
	double	rad;

	rad = data->p_a;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move_minimap(data, cos(rad), sin(rad));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move_minimap(data, -cos(rad), -sin(rad));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move_minimap(data, cos(rad - M_PI / 2), sin(rad - M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move_minimap(data, cos(rad + M_PI / 2), sin(rad + M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_a += rad_convertor(1.0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_a -= rad_convertor(1.0);
	if (data->p_a < rad_convertor(0))
		data->p_a += rad_convertor(360);
	if (data->p_a >= rad_convertor(360))
		data->p_a -= rad_convertor(360);
}
