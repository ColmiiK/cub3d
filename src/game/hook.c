#include <cub3d.h>

static void	debug_print_mlx(t_data *data)
{
	char				buffer[250];
	static mlx_image_t	*img;

	sprintf(buffer, "p_x: %.1f\np_y: %.1f\np_a: %03.0f\nm_x: %04d\nm_y: %04d\nfps: %.1f\n",
		data->p_x, data->p_y, data->p_a, data->m_x, data->m_y, 1 / data->mlx->delta_time);
	if (img)
		mlx_delete_image(data->mlx, img);
	img = mlx_put_string(data->mlx, buffer, 5, 5);
}

void ft_reload_gun(t_tex *t, int anim_counter)
{
	printf("anim_counter: %d\n", anim_counter);
	t->i_sprite[anim_counter - 1]->enabled = false;
	t->i_sprite[anim_counter]->enabled = true;
}

void ft_shoot_the_gun(t_data *data, int *anim_counter)
{
	if (*anim_counter == 12)
	{
		data->texture->i_sprite[*anim_counter - 1]->enabled = false;
		data->texture->i_sprite[0]->enabled = true;
		*anim_counter = -1;
	}
	else
	{
		data->texture->i_sprite[*anim_counter - 1]->enabled = false;
		data->texture->i_sprite[*anim_counter]->enabled = true;
	}
	usleep(150000);
	*anim_counter = *anim_counter + 1;
}

void	ft_hook(void *param)
{
	t_data	*data;
	static int anim_counter = 0;

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
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		ft_shoot_the_gun(data, &anim_counter);
	if (data->p_a < 0)
		data->p_a += 360;
	if (data->p_a >= 360)
		data->p_a -= 360;
	mlx_get_mouse_pos(data->mlx, &data->m_x, &data->m_y);
	debug_print_mlx(data); // Debug print of player data
}

