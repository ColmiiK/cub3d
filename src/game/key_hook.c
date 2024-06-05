#include <cub3d.h>

static void	ft_open_door(t_data *data, int y, int x)
{
	printf("attempting to open door at map[%d][%d]: %c\n", y, x, data->map[y][x]);
	if (data->map[y][x] == 'L')
	{
		data->map[y][x] = 'U';
		ft_fill_square(UNLOCKED, data->minimap,
			x * W_WIDTH / 50, y * W_HEIGHT / 50);
	}
	else if (data->map[y][x] == 'U')
	{
		data->map[y][x] = 'L';
		ft_fill_square(LOCKED, data->minimap,
			x * W_WIDTH / 50, y * W_HEIGHT / 50);
	}
}

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = (int)data->p_x;
	y = (int)data->p_y;
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
	{
		if (data->p_a >= 270 - 45 && data->p_a < 270 + 45)
			ft_open_door(data, y - 1, x);
		if (data->p_a >= 90 - 45 && data->p_a < 90 + 45)
			ft_open_door(data, y + 1, x);
		if (data->p_a >= 180 - 45 && data->p_a < 180 + 45)
			ft_open_door(data, y, x - 1);
		if ((data->p_a >= 0 && data->p_a < 0 + 45)
			|| (data->p_a >= 360 - 45 && data->p_a < 360))
			ft_open_door(data, y, x + 1);
	}
}
