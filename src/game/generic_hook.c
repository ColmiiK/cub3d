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
			data->texture->i_sprite[anim_counter - 1]->enabled = false;
			data->texture->i_sprite[anim_counter]->enabled = true;
		}
		anim_counter = anim_counter + 1;
	}
}

static void	ft_player_movement(t_data *data)
{
	double	rad;

	rad = data->p_a * M_PI / 180.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move_minimap(data, cos(rad), sin(rad));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move_minimap(data, -cos(rad), -sin(rad));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move_minimap(data, cos(rad - M_PI / 2), sin(rad - M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move_minimap(data, cos(rad + M_PI / 2), sin(rad + M_PI / 2));
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		data->p_a += 1.0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		data->p_a -= 1.0;
	if (data->p_a < 0)
		data->p_a += 360;
	if (data->p_a >= 360)
		data->p_a -= 360;
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	data->frame++;
	if (data->shooting_gun == true)
		ft_shoot_the_gun(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_player_movement(data);
	mlx_get_mouse_pos(data->mlx, &data->m_x, &data->m_y);
	debug_print_mlx(data); // Debug print of player data
}
