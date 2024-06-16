#include <cub3d.h>

// We're starting a loop in which we'll check, based in x, if the matrix 
// square where we are is a wall, returning the coordinates
t_coord	*x_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*x_cross;

	x_cross = first_step_x(data, tools);
	tools->distance_x = x_distance(data);
	while (data->map[(int)x_cross->y][(int)x_cross->x] != '1'
		&& ft_delimiter(data, x_cross) != 1)
	{
		if (tools->distance_x != 1)
		{
			x_cross->y += tools->vector_y;
			x_cross->x += (tools->distance_x * tools->vector_x);
		}
		else
			x_cross->x += tools->vector_x;
	}
	return (x_cross);
}

// We're starting a loop in which we'll check, based in y, if the matrix 
// square where we are is a wall, returning the coordinates
t_coord	*y_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*y_cross;

	y_cross = first_step_y(data, tools);
	tools->distance_y = y_distance(data);
	while (data->map[(int)y_cross->x][(int)y_cross->y] != '1'
		&& ft_delimiter(data, y_cross) != 1)
	{
		if (tools->distance_y != 1)
		{
			y_cross->y += (tools->distance_y * tools->vector_y);
			y_cross->x += tools->vector_x;
		}
		else
			y_cross->y += tools->vector_y;
	}
	return (y_cross);
}

// This function will return the shortest distance to the closest
// wall checking both collision coords from the wall_finders functions
double	wall_distance(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	tools->x_cross = x_wall_finder(data, tools);
	tools->y_cross = y_wall_finder(data, tools);
	tools->distance_x = sqrt(pow(tools->x_cross->x - data->p_x, 2)
			+ pow(tools->x_cross->y - data->p_y, 2));
	tools->distance_y = sqrt(pow(tools->y_cross->x - data->p_x, 2)
			+ pow(tools->y_cross->y - data->p_y, 2));
	if (tools->distance_x > tools->distance_y)
		return (tools->distance_y);
	return (tools->distance_x);
}
