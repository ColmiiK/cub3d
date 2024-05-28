#include <cub3d.h>

static void ft_fill_square(int color, mlx_image_t *minimap, int x, int y)
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

static void ft_fill_minimap(t_data *data, mlx_image_t *minimap)
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

static void ft_center_minimap(mlx_image_t *minimap, mlx_image_t *player)
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

void ft_draw_minimap(t_data *data)
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
	data->p_x += (x / (R_WIDTH + 0.0));
	data->p_y += (y / (R_HEIGHT + 0.0));
	data->minimap->instances[0].x -= x;
	data->minimap->instances[0].y -= y;
}
