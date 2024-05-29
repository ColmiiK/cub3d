#include <cub3d.h>

int	ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", false);
	data->game_img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->mlx)
		return (1);
	mlx_loop_hook(data->mlx, &ft_keyhook, data);
	ft_draw_game(data);
	printf("p_a == %f\n", data->p_a);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
