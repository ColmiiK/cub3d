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

static void ft_shoot_the_gun(t_data *data)
{
	static int anim_counter = 0;

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

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	data->frame++;
	if (data->shooting_gun == true)
		ft_shoot_the_gun(data);
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

void ft_mousehook(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_data *data;

	(void)mods;
	data = param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		data->shooting_gun = true;
}

void ft_open_door(t_data *data, int y, int x)
{
	printf("attempting to open door at map[%d][%d]: %c\n", y, x, data->map[y][x]);
	if (data->map[y][x] == 'L')
	{
		data->map[y][x] = 'U';
		ft_fill_square(UNLOCKED, data->minimap, x * R_WIDTH, y * R_HEIGHT);
	}
	else if (data->map[y][x] == 'U')
	{
		data->map[y][x] = 'L';
		ft_fill_square(LOCKED, data->minimap, x * R_WIDTH, y * R_HEIGHT);
	}
}

void ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data *data;
	int x;
	int y;

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
		if ((data->p_a >= 0 && data->p_a < 0 + 45) || (data->p_a >= 360 - 45 && data->p_a < 360))
			ft_open_door(data, y, x + 1);
	}
}
