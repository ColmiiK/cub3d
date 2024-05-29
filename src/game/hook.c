#include <cub3d.h>

static void	debug_print_mlx(t_data *data)
{
	char				buffer[250];
	static mlx_image_t	*img;

	sprintf(buffer, "p_x: %g\np_y: %g\np_a: %g\nm_x: %d\nm_y: %d\n",
		data->p_x, data->p_y, data->p_a, data->m_x, data->m_y);
	if (img)
		mlx_delete_image(data->mlx, img);
	img = mlx_put_string(data->mlx, buffer, 5, W_HEIGHT - 20);
}

void	ft_keyhook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move_minimap(data, 0, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move_minimap(data, 0, +1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move_minimap(data, -1, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move_minimap(data, +1, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_a += 1.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_a -= 1.0;
	if (data->p_a < 0)
		data->p_a += 360;
	if (data->p_a >= 360)
		data->p_a -= 360;
	mlx_get_mouse_pos(data->mlx, &data->m_x, &data->m_y);
	debug_print_mlx(data); // Debug print of player data
}
