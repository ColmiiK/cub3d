#include <cub3d.h>

int ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	ft_draw_minimap(data);
	mlx_loop_hook(data->mlx, &ft_keyhook, data);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
