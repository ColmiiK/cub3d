#include <cub3d.h>

// We're starting a loop in which we'll check, based in x, if the matrix 
// square where we are is a wall, returning the coordinates
t_coord	*x_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*x_cross;

	x_cross = first_step_x(data, tools);
	tools->distance_x = x_distance(data);
	// printf("height == %d\twidth == %d\n", data->height, data->width);
	while (x_cross->x >= 0 && x_cross->x < data->width && x_cross->y >= 0 && x_cross->y < data->height)
	{
		// printf("map[%d][%d] == %c\n", (int)x_cross->y, (int)x_cross->x, data->map[(int)x_cross->y][(int)x_cross->x]);
		if (x_cross->y > 0 && (data->map[(int)x_cross->y - 1][(int)x_cross->x] == '1' || data->map[(int)x_cross->y - 1][(int)x_cross->x] == ' ')
			&& tools->vector_y == -1)
			break ;
		else if (data->map[(int)x_cross->y][(int)x_cross->x] == '1' || data->map[(int)x_cross->y][(int)x_cross->x] == ' ')
			break ; 
		else
		{
			if (tools->distance_x != -1)
				x_cross->x += (tools->distance_x * tools->vector_x);
			x_cross->y += tools->vector_y;
		}
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
	while ((y_cross->y >= 0 && y_cross->y <= data->height)
		&& (y_cross->x >= 0 && y_cross->x <= data->width))
	{
		if (y_cross->x > 0 && data->map[(int)y_cross->y][(int)y_cross->x - 1] == '1'
			&& tools->vector_x == -1)
			break ;
		else if (data->map[(int)y_cross->y][(int)y_cross->x] == '1')
			break ;
		else
		{
			if (tools->distance_y != -1)
				y_cross->y += (tools->distance_y * tools->vector_y);
			y_cross->x += tools->vector_x;
		}
	}
	return (y_cross);
}

// This function will return the shortest distance to the closest
// wall checking both collision coords from the wall_finders functions
t_tools	*wall_distance(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	tools->x_cross = x_wall_finder(data, tools);
	tools->y_cross = y_wall_finder(data, tools);

	if (tools->distance_x != -1)
	{
		tools->distance_x = sqrt(pow(tools->x_cross->x - data->p_x, 2)
				+ pow(tools->x_cross->y - data->p_y, 2));
	}
	if (tools->distance_y != -1)
	{
		tools->distance_y = sqrt(pow(tools->y_cross->x - data->p_x, 2)
				+ pow(tools->y_cross->y - data->p_y, 2));
	}
	return (tools);
}
