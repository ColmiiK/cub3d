#include <cub3d.h>

// Calculates the distance that separates de 'x' crosses
double	x_distance(t_data *data)
{
	double	distance_x;

	if ((fabs)(1 / tan(data->p_a)) == 0
		|| (fabs)(1 / tan(data->p_a)) >= data->width)
		distance_x = 1;
	else
		distance_x = (fabs)(1 / tan(data->p_a));
	return (distance_x);
}

// Calculates the distance that separates the 'y' crosses
double	y_distance(t_data *data)
{
	double	distance_y;

	if ((fabs)(tan(data->p_a)) == 0
		|| (fabs)(tan(data->p_a)) >= data->height)
		distance_y = 1;
	else
		distance_y = (fabs)(tan(data->p_a));
	return (distance_y);
}

// Defines a unit vector depending where we're looking at
t_tools	*vector_define(t_data *data)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		return (NULL);
	tools->vector_x = 1;
	tools->vector_y = 1;
	tools->x_cross = NULL;
	tools->y_cross = NULL;
	if (!(data->p_a >= 0 && data->p_a <= M_PI))
		tools->vector_y = -1;
	if (data->p_a >= rad_convertor(90)
		&& data->p_a <= rad_convertor(270))
		tools->vector_x = -1;
	return (tools);
}
