#include <cub3d.h>

void	ft_draw_background(t_data *data)
{
	int	coord_x;
	int	coord_y;

	coord_x = 0;
	while (coord_x < W_WIDTH)
	{
		coord_y = 0;
		while (coord_y < W_HEIGHT)
		{
			if (coord_y > W_HEIGHT / 50 && coord_x > W_WIDTH / 50
				&& coord_y < W_HEIGHT / 50 * 8 && coord_x < W_WIDTH / 50 * 8)
				;
			else if (coord_y < W_HEIGHT / 2)
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->ceiling);
			else
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->floor);
			coord_y++;
		}
		coord_x++;
	}
}

static void	ft_draw_border(t_data *data)
{
	int	coord_x;
	int	coord_y;

	coord_x = W_WIDTH / 50;
	while (coord_x < W_WIDTH)
	{
		coord_y = W_HEIGHT / 50;
		while (coord_y < W_HEIGHT)
		{
			if ((coord_y < W_HEIGHT / 50 * 1.2 && coord_x <= W_WIDTH / 50 * 8.2)
				|| (coord_x < W_HEIGHT / 50 * 1.2
					&& coord_y <= W_WIDTH / 50 * 8.2))
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->ceiling - 100);
			if ((coord_y > W_HEIGHT / 50 && coord_x > W_WIDTH / 50)
				&& (coord_y >= W_HEIGHT / 50 * 8 || coord_x >= W_WIDTH / 50 * 8)
				&& (coord_y <= W_HEIGHT / 50 * 8.2
					&& coord_x <= W_HEIGHT / 50 * 8.2))
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->ceiling - 100);
			coord_y++;
		}
		coord_x++;
	}
}

void	ft_draw_game(t_data *data)
{

	ft_draw_background(data);
	ft_draw_border(data);
	ft_draw_minimap(data);
	mlx_image_to_window(data->mlx, data->game_img, 0, 0);
	mlx_image_to_window(data->mlx, data->wall, 0, 0);
	// data->p_a = 210;
	ray_loop(data);	
}
