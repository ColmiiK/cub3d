#include <cub3d.h>

static void	ft_draw_player(t_data *data, int x, int y)
{
	int	len_x;
	int	len_y;

	len_x = x + (W_HEIGHT / 50 / 2);
	len_y = y + (W_HEIGHT / 50 / 2);
	while (++y < len_y)
	{
		x = len_x - (W_HEIGHT / 50 / 2);
		while (++x < len_x)
			mlx_put_pixel(data->player, x, y, RED);
	}
}

static void	ft_fill_minimap(t_data *data, mlx_image_t *minimap)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				ft_fill_square(BLACK, minimap,
					j * W_HEIGHT / 50, i * W_HEIGHT / 50);
			else if (data->map[i][j] == ' ')
				ft_fill_square(TRANSPARENT, minimap,
					j * W_HEIGHT / 50, i * W_HEIGHT / 50);
			else
				ft_fill_square(WHITE, minimap,
					j * W_HEIGHT / 50, i * W_HEIGHT / 50);
		}
	}
}

static void	ft_center_minimap(mlx_image_t *minimap, mlx_image_t *player)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (player->instances[0].x + x < W_HEIGHT / 20)
		x++;
	while (player->instances[0].x + x > W_HEIGHT / 20)
		x--;
	while (player->instances[0].y + y < W_HEIGHT / 20)
		y++;
	while (player->instances[0].y + y > W_HEIGHT / 20)
		y--;
	player->instances[0].x += x + W_HEIGHT / 50;
	player->instances[0].y += y + W_HEIGHT / 50;
	minimap->instances[0].x += x + W_HEIGHT / 50;
	minimap->instances[0].y += y + W_HEIGHT / 50;
}

void	ft_draw_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx,
			data->width * W_HEIGHT / 50, data->height * W_HEIGHT / 50);
	data->player = mlx_new_image(data->mlx,
			W_HEIGHT / 50 * 2, W_HEIGHT / 50 * 2);
	ft_fill_minimap(data, data->minimap);
	ft_draw_player(data, W_HEIGHT / 50 - (W_HEIGHT / 50 / 4),
		W_HEIGHT / 50 - (W_HEIGHT / 50 / 4));
	mlx_image_to_window(data->mlx, data->minimap, 0, 0);
	mlx_image_to_window(data->mlx, data->player, (data->p_x - 1) * W_HEIGHT / 50,
		(data->p_y - 1) * W_HEIGHT / 50);
	ft_center_minimap(data->minimap, data->player);
}

void	ft_move_minimap(t_data *data, double dx, double dy)
{
	static double	fx = 0.0;
	static double	fy = 0.0;
	int				ix;
	int				iy;

	if (data->map[(int)(data->p_y + (dy / 3))][(int)(data->p_x + (dx / 3))] == '1'
		|| data->map[(int)(data->p_y + (dy / 3))][(int)(data->p_x + (dx / 3))] == ' ')
	{
		fx = 0.0;
		fy = 0.0;
		return ;
	}
	fx += dx;
	fy += dy;
	ix = (int)fx;
	iy = (int)fy;
	if (ix != 0)
	{
		data->p_x += ix / (W_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].x -= ix;
		fx -= ix;
	}
	if (iy != 0)
	{
		data->p_y += iy / (W_HEIGHT / 50 + 0.0);
		data->minimap->instances[0].y -= iy;
		fy -= iy;
	}
}
