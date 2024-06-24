#include <cub3d.h>

void	ft_draw_walls(t_data *data, int x, t_tools *tools)
{
	int	y;

	y = ((W_HEIGHT - tools->wall_size) / 2);
	while (y < ((W_HEIGHT + tools->wall_size) / 2))
	{
		if (y > W_HEIGHT / 50 && x > W_HEIGHT / 50
			&& y < W_HEIGHT / 50 * 8.2 && x < W_HEIGHT / 50 * 8.2)
			;
		else if (y < W_HEIGHT && y > 0)
			mlx_put_pixel(data->wall, x, y, tools->orientation);
		y++;
	}
}

// Prototype of the loop that will shoot one ray per coordinate
// and draw the needed line
void	ray_loop(t_data *data)
{
	t_tools	*tools;
	double	scale;
	int		width;

	width = 0;
	scale = rad_convertor((VISION + 0.0) / (W_WIDTH + 0.0));
	if (data->p_a - rad_convertor(45) < 0)
		data->angle = data->p_a + rad_convertor(315);
	else
		data->angle = data->p_a - rad_convertor(45);
	while (width < W_WIDTH)
	{
		tools = wall_distance(data);
		define_orientation(tools);
		ft_draw_walls(data, width, tools);
		if (data->angle + scale >= 2 * M_PI)
			data->angle = data->angle - (2 * M_PI) + scale;
		else
			data->angle = data->angle + scale;
		width++;
		free(tools->x_cross);
		free(tools->y_cross);
		free(tools);
	}
}
