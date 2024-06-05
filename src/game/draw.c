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
			if (coord_y > R_HEIGHT && coord_x > R_WIDTH
				&& coord_y < R_HEIGHT * 8 && coord_x < R_WIDTH * 8)
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

static void ft_draw_border(t_data *data)
{
	int	coord_x;
	int	coord_y;

	coord_x = R_WIDTH;
	while (coord_x < W_WIDTH)
	{
		coord_y = R_HEIGHT;
		while (coord_y < W_HEIGHT)
		{
			if ((coord_y < R_HEIGHT * 1.2 && coord_x <= R_WIDTH * 8.2)
				|| (coord_x < R_HEIGHT * 1.2 && coord_y <= R_WIDTH * 8.2))
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->ceiling - 100);
			if ((coord_y > R_HEIGHT && coord_x > R_WIDTH)
				&& (coord_y >= R_HEIGHT * 8 || coord_x >= R_WIDTH * 8)
				&& (coord_y <= R_HEIGHT * 8.2 && coord_x <= R_HEIGHT * 8.2))
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
	data->p_a = 45 * (M_PI / 180);
	igomeow(data);	
}
