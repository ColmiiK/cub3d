#include <cub3d.h>

void ft_fill_square(int color, mlx_image_t *minimap, int x, int y)
{
	int len_x;
	int len_y;

	len_x = x + R_WIDTH;
	len_y = y + R_HEIGHT;
	while (++y < len_y)
	{
		x = len_x - R_WIDTH;
		while (++x < len_x)
			mlx_put_pixel(minimap, x, y, color);
	}
}

void ft_fill_minimap(t_data *data, mlx_image_t *minimap)
{
	int i;
	int j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				ft_fill_square(BLACK, minimap, j * R_WIDTH, i * R_HEIGHT);
			else if (data->map[i][j] != ' ')
				ft_fill_square(WHITE, minimap, j * R_WIDTH, i * R_HEIGHT);
		}
	}
}

void ft_center_minimap(mlx_image_t *minimap, mlx_image_t *player)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (player->instances[0].x + x < 100)
		x++;
	while (player->instances[0].x + x > 100)
		x--;
	while (player->instances[0].y + y < 100)
		y++;
	while (player->instances[0].y + y > 100)
		y--;
	player->instances[0].x += x;
	player->instances[0].y += y;
	minimap->instances[0].y += y;
	minimap->instances[0].x += x;
}

void ft_redraw(t_data *data)
{
	data->player = mlx_new_image(data->mlx, R_WIDTH * 2, R_HEIGHT * 2);
	data->minimap = mlx_new_image(data->mlx, data->width * R_WIDTH, data->height * R_HEIGHT);
	ft_fill_minimap(data, data->minimap);
	ft_fill_square(RED, data->player, R_WIDTH, R_HEIGHT);
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	mlx_image_to_window(data->mlx, data->player, (data->p_x - 1) * R_WIDTH, (data->p_y - 1) * R_HEIGHT);
	ft_center_minimap(data->minimap, data->player);
}

void ft_move_minimap(t_data *data, int x, int y)
{
	data->p_x += x;
	data->p_y += y;
	data->minimap->instances[0].x -= x;
	data->minimap->instances[0].y -= y;
}

void ft_keyhook(void *param)
{
	t_data *data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
		ft_move_minimap(data, 0, -1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		ft_move_minimap(data, 0, +1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_move_minimap(data, -1, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_move_minimap(data, +1, 0);
	if (mlx_is_key_down(data->mlx, MLX_KEY_Q))
	{
		printf("\nPlayer x: \t%f\n", data->p_x);
		printf("Player y: \t%f\n", data->p_y);
	}
}

int ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	ft_redraw(data);
	mlx_loop_hook(data->mlx, &ft_keyhook, data);

	mlx_loop(data->mlx);
	return (0);
}
