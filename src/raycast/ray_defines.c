#include <cub3d.h>

// Defines the orientation of the wall we're seeing
void	define_orientation(t_tools *tools)
{
	if (tools->distance_x > tools->distance_y)
	{
		tools->wall_size = 400 / tools->distance_y;
		if (tools->vector_x < 0) // WEST
			tools->orientation = BLACK;
		else // EAST
			tools->orientation = WHITE;
	}
	else
	{
		tools->wall_size = 400 / tools->distance_x;
		if (tools->vector_y < 0) // NORTH
			tools->orientation = PINK;
		else // SOUTH
			tools->orientation = BLUE;
	}
}

// Calculates the distance that separates de 'x' crosses
double	x_distance(t_data *data)
{
	double	distance_x;

	if ((fabs)(1 / tan(data->angle)) == 0
		|| (fabs)(1 / tan(data->angle)) >= data->width)
		distance_x = 1;
	else
		distance_x = (fabs)(1 / tan(data->angle));
	return (distance_x);
}

// Calculates the distance that separates the 'y' crosses
double	y_distance(t_data *data)
{
	double	distance_y;

	if ((fabs)(tan(data->angle)) == 0
		|| (fabs)(tan(data->angle)) >= data->height)
		distance_y = 1;
	else
		distance_y = (fabs)(tan(data->angle));
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
	if (!(data->angle >= 0 && data->angle <= M_PI))
		tools->vector_y = -1;
	if (data->angle >= rad_convertor(90)
		&& data->angle <= rad_convertor(270))
		tools->vector_x = -1;
	return (tools);
}
