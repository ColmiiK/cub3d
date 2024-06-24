#include <cub3d.h>

static void	ft_debug_print_mlx(t_data *data)
{
	char	buffer1[150];
	char	buffer2[150];
	char	*temp;

	sprintf(buffer1, "p_x: %.1f p_y: %.2f p_a: %.2f ",
		data->p_x, data->p_y, data->p_a);
	sprintf(buffer2, "m_x: %04d m_y: %04d fps: %.1f",
		data->m_x, data->m_y, 1 / data->mlx->delta_time);
	temp = ft_strjoin(buffer1, buffer2);
	data->debug_info = mlx_put_string(data->mlx, temp, 5, 0);
	free(temp);
}

static void	ft_shoot_the_gun(t_data *data)
{
	static int	anim_counter = 0;

	if (data->frame % 5 == 0)
	{
		if (anim_counter == 5)
		{
			data->texture->i_sprite[anim_counter - 1]->enabled = false;
			data->texture->i_sprite[0]->enabled = true;
			anim_counter = -1;
			data->shooting_gun = false;
		}
		else
		{
			if (anim_counter == -1 || anim_counter == 0)
				anim_counter = 1;
			data->texture->i_sprite[anim_counter - 1]->enabled = false;
			data->texture->i_sprite[anim_counter]->enabled = true;
		}
		anim_counter = anim_counter + 1;
	}
}

static void	ft_move_camera(t_data *data)
{
	mlx_get_mouse_pos(data->mlx, &data->m_x, &data->m_y);
	data->p_a += rad_convertor((data->m_x - (W_WIDTH / 2)) / 50);
	mlx_set_mouse_pos(data->mlx, W_WIDTH / 2, W_HEIGHT / 2);
}

static void	ft_clean_walls(t_data *data)
{
	int	y;
	int	x;

	x = -1;
	while (++x < W_HEIGHT)
	{
		y = -1;
		while (++y < W_WIDTH)
		{
			mlx_put_pixel(data->wall, y, x, TRANSPARENT);
			mlx_put_pixel(data->line, y, x, TRANSPARENT);
		}
	}
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	data->frame++;
	ft_clean_walls(data);
	ray_loop(data);
	if (data->shooting_gun == true)
		ft_shoot_the_gun(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_player_movement(data);
	ft_move_camera(data);
	if (data->debug_info)
		mlx_delete_image(data->mlx, data->debug_info);
	if (data->debug_flag)
		ft_debug_print_mlx(data);
}
