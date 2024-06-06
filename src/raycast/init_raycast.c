#include <cub3d.h>

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
	if (data->p_a >= 0 && data->p_a <= 180)
		tools->vector_y = -1;
	if (data->p_a >= 90 && data->p_a <= 270)
		tools->vector_x = -1;
	return (tools);
}

void	x_wall_finder(t_data *data, t_tools **tools)
{
	t_coord	*x_cross;

	x_cross = malloc(sizeof(t_coord));
	if (!x_cross)
		return ;
	x_cross->x = data->p_x;
	x_cross->y = data->p_y;
	(*tools)->distance_x = (1 / tan(data->p_a)) * (*tools)->vector_x;
	while (data->map[(int)(x_cross->x)][(int)(x_cross->y)] != '1')
	{
		if (data->p_a != 0 && data->p_a != 180)
		{
			x_cross->x += (*tools)->distance_x;
			x_cross->y -= 1 * (*tools)->vector_y;
		}
		else
			x_cross->x += 1 * (*tools)->vector_x;
		printf("calc coords == [%d][%d]\n", (int)(x_cross->x), (int)(x_cross->y));
		printf("x_cross->x = [%f] && x_cross->y = [%f]\n", x_cross->x, x_cross->y);
	}
	(*tools)->x_cross = x_cross;
}

void	y_wall_finder(t_data *data, t_tools **tools)
{
	t_coord	*y_cross;

	y_cross = malloc(sizeof(t_coord));
	if (!y_cross)
		return ;
	y_cross->x = data->p_x;
	y_cross->y = data->p_y;
	(*tools)->distance_y = tan(data->p_a) * (*tools)->vector_y;
	while (data->map[(int)y_cross->x][(int)y_cross->y] != '1')
	{
		if (data->p_a != 90 && data->p_a != 270)
		{
			y_cross->y -= (*tools)->distance_y;
			y_cross->x += 1 * (*tools)->vector_x;
		}
		else
			y_cross->y -= 1 * (*tools)->vector_y;
		printf("calc coords == [%d][%d]\n", (int)(y_cross->x), (int)(y_cross->y));
		printf("y_cross->x = [%f] && y_cross->y = [%f]\n", y_cross->x, y_cross->y);
	}
	(*tools)->y_cross = y_cross;
}

// double	first_step(t_data *data)
// {

// }

void	igomeow(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	printf("Entering first wall_finder\n\n\n");
	// data->p_x += 0.5;
	// data->p_y -= 0.5;
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
