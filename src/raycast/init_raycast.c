#include <cub3d.h>

int	ft_delimiter(t_data *data, t_coord *cross)
{
	if (cross->x <= 0 || cross->x >= data->width
		|| cross->y <= 0 || cross->y >= data->height)
		return (1);
	return (0);
}

t_coord	*x_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*x_cross;

	x_cross = first_step_x(data, tools);
	tools->distance_x = x_distance(data);
	printf("\t\tX_WALL_FINDER\n");
	printf("\t\tdistance_x = %f\n", tools->distance_x);
	printf("\t\tinitial coord: [%f][%f]\n", x_cross->x, x_cross->y);
	while (data->map[(int)x_cross->x][(int)x_cross->y] != '1'
		&& ft_delimiter(data, x_cross) != 1)
	{
		if (tools->distance_x != 1)
		{
			x_cross->y += tools->vector_y;
			x_cross->x += (tools->distance_x * tools->vector_x);
			printf("\t\tcoord loop: [%f][%f]\n", x_cross->x, x_cross->y);
			printf("\t\tmap valor == %c\n", data->map[(int)x_cross->x][(int)x_cross->y]);
		}
		else
			x_cross->x += tools->vector_x;
	}
	return (x_cross);
}

t_coord	*y_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*y_cross;

	y_cross = first_step_y(data, tools);
	tools->distance_y = y_distance(data);
	printf("\t\tY_WALL_FINDER\n");
	printf("\t\tdistance_x = %f\n", tools->distance_y);
	printf("\t\tinitial coord: [%f][%f]\n", y_cross->x, y_cross->y);
	while (data->map[(int)y_cross->x][(int)y_cross->y] != '1'
		&& ft_delimiter(data, y_cross) != 1)
	{
		if (tools->distance_y != 1)
		{
			y_cross->y += (tools->distance_y * tools->vector_y);
			y_cross->x += tools->vector_x;
			printf("\t\tcoord loop: [%f][%f]\n", y_cross->x, y_cross->y);
			printf("\t\tmap valor == %c\n", data->map[(int)y_cross->x][(int)y_cross->y]);
		}
		else
			y_cross->y += tools->vector_y;
	}
	return (y_cross);
}

void	igomeow(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	printf("Entering first wall_finder\n\n\n");
	if (data->p_a != rad_convertor(90) && data->p_a != rad_convertor(270))
	{
		tools->x_cross = x_wall_finder(data, tools);
		printf("x_cross == [%f][%f]\n\n\n", tools->x_cross->x, tools->x_cross->y);
	}
	if (data->p_a != 0 && data->p_a != M_PI)
	{
		tools->y_cross = y_wall_finder(data, tools);
		printf("y_cross == [%f][%f]\n\n\n", tools->y_cross->x, tools->y_cross->y);
	}
}
