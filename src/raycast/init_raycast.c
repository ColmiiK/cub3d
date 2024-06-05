#include <cub3d.h>

void	x_wall_finder(t_data *data, t_tools **tools)
{
	t_coord	*x_cross;

	x_cross = first_step_x(data, *tools);
	(*tools)->distance_x = (1 / tan(data->p_a)) * (*tools)->vector_x;
	while (data->map[(int)(x_cross->x)][(int)(x_cross->y)] != '1'
		&& x_cross->x <= data->width && x_cross->y <= data->height)
	{
		if (data->p_a != 0 && data->p_a != 180)
		{
			x_cross->x += (*tools)->distance_x;
			x_cross->y -= 1 * (*tools)->vector_y;
		}
		else
			x_cross->x += 1 * (*tools)->vector_x;
		// printf("calc coords == [%d][%d]\n", (int)(x_cross->x), (int)(x_cross->y));
		// printf("x_cross->x = [%f] && x_cross->y = [%f]\n", x_cross->x, x_cross->y);
	}
	(*tools)->x_cross = x_cross;
}

void	y_wall_finder(t_data *data, t_tools **tools)
{
	t_coord	*y_cross;

	y_cross = first_step_y(data, *tools);
	(*tools)->distance_y = tan(data->p_a) * (*tools)->vector_y;
	while (data->map[(int)y_cross->x][(int)y_cross->y] != '1'
		&& y_cross->x <= data->width && y_cross->y <= data->height)
	{
		if (data->p_a != 90 && data->p_a != 270)
		{
			y_cross->y -= (*tools)->distance_y;
			y_cross->x += 1 * (*tools)->vector_x;
		}
		else
			y_cross->y -= 1 * (*tools)->vector_y;
		// printf("calc coords == [%d][%d]\n", (int)(y_cross->x), (int)(y_cross->y));
		// printf("y_cross->x = [%f] && y_cross->y = [%f]\n", y_cross->x, y_cross->y);
	}
	(*tools)->y_cross = y_cross;
}

void	igomeow(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	printf("Entering first wall_finder\n\n\n");
	if (data->p_a != 90 && data->p_a != 270)
	{
		x_wall_finder(data, &tools);
		printf("x_cross == [%f][%f]\n\n\n", tools->x_cross->x, tools->x_cross->y);
	}
	if (data->p_a != 0 && data->p_a != 180)
	{
		y_wall_finder(data, &tools);
		printf("y_cross == [%f][%f]\n\n\n", tools->y_cross->x, tools->y_cross->y);
	}
}
