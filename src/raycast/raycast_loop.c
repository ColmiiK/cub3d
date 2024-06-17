#include <cub3d.h>

void	ft_draw_walls(t_data *data, int x, t_tools *tools)
{
	int	y;

	y = ((W_HEIGHT - tools->wall_size) / 2);
	while (y < ((W_HEIGHT + tools->wall_size) / 2))
	{
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
	scale = rad_convertor(0.09);
	if (data->p_a - 45 < 0)
		data->p_a = data->p_a + 315;
	else
		data->p_a = data->p_a - 45;
	data->p_a = rad_convertor(data->p_a);
	while (width <= W_WIDTH)
	{
		tools = wall_distance(data);
		define_orientation(tools);
		// printf("distance en width(%d) == %f, ang == %f\n", width, distance, data->p_a);
		ft_draw_walls(data, width, tools);
		if (data->p_a + scale >= 2 * M_PI)
			data->p_a = data->p_a - (2 * M_PI) + scale;
		else
			data->p_a = data->p_a + scale;
		width++;
	}
}