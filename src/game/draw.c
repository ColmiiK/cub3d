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
			if (coord_y < W_HEIGHT / 2)
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

void	ft_draw_game(t_data *data)
{

	ft_draw_background(data);
	mlx_image_to_window(data->mlx, data->game_img, 0, 0);
	
	ft_draw_minimap(data);
}
