#include <cub3d.h>

// Prototype of the loop that will shoot one ray per coordinate
// and draw the needed line
void	ray_loop(t_data *data)
{
	double	distance;
	double	scale;
	int		width;

	width = 0;
	scale = rad_convertor(0.6);
	if (data->p_a - 45 < 0)
		data->p_a = data->p_a + 315;
	else
		data->p_a = data->p_a - 45;
	data->p_a = rad_convertor(data->p_a);
	while (width <= W_WIDTH)
	{
		distance = wall_distance(data);
		printf("distance en width(%d) == %f, ang == %f\n", width, distance, data->p_a);
		if (data->p_a + scale >= 2 * M_PI)
			data->p_a = data->p_a - (2 * M_PI) + scale;
		else
			data->p_a = data->p_a + scale;
		width++;
	}
}
