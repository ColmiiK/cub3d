#include <cub3d.h>

void ft_draw_walls(t_data *data, int x, int size)
{
	int y;

	y = (size / 2) * -1 ;
	while (++y < size / 2)
		mlx_put_pixel(data->wall, x, y + (W_HEIGHT / 2), BLACK);
}

// Prototype of the loop that will shoot one ray per coordinate
// and draw the needed line
void	ray_loop(t_data *data)
{
	double	distance;
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
		distance = wall_distance(data);
		// printf("distance en width(%d) == %f, ang == %f\n", width, distance, data->p_a);
		ft_draw_walls(data, width, (distance * 100));
		if (data->p_a + scale >= 2 * M_PI)
			data->p_a = data->p_a - (2 * M_PI) + scale;
		else
			data->p_a = data->p_a + scale;
		width++;
	}
}
