#include <cub3d.h>

void	ft_draw_walls(t_data *data, int x, t_tools *tools)
{
	int	size;
	int	y;

	size = 400 / tools->distance_x;
	if (tools->distance_x > tools->distance_y)
		size = 400 / tools->distance_y;
	y = ((W_HEIGHT - size) / 2);
	while (y < ((W_HEIGHT + size) / 2))
	{
		if (tools->distance_x > tools->distance_y)
			mlx_put_pixel(data->wall, x, y, BLACK);
		else
			mlx_put_pixel(data->wall, x, y, WHITE);
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
	scale = rad_convertor(0.09);
	if (data->p_a - 45 < 0)
		data->p_a = data->p_a + 315;
	else
		data->p_a = data->p_a - 45;
	data->p_a = rad_convertor(data->p_a);
	while (width <= W_WIDTH)
	{
		tools = wall_distance(data);
		// printf("distance en width(%d) == %f, ang == %f\n", width, distance, data->p_a);
		ft_draw_walls(data, width, tools);
		if (data->p_a + scale >= 2 * M_PI)
			data->p_a = data->p_a - (2 * M_PI) + scale;
		else
			data->p_a = data->p_a + scale;
		width++;
	}
}
