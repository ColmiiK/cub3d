#include <cub3d.h>

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = (int)data->p_x;
	y = (int)data->p_y;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		data->debug_flag = !data->debug_flag;
}
