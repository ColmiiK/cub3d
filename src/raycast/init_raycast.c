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
	while (data->map[(int)(x_cross->x)][(int)(x_cross->y)] != '1')
	{
		if (data->p_a != 0 && data->p_a != 180)
		{
			x_cross->x += (1 / tan(x_cross->x));
			x_cross->y += 1 * (*tools)->vector_y;
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
	while (data->map[(int)y_cross->x][(int)y_cross->y] != '1')
	{
		if (data->p_a != 90 && data->p_a != 270)
		{
			y_cross->y += tan(y_cross->y);
			y_cross->x += 1 * (*tools)->vector_x;
		}
		else
			y_cross->y -= 1 * (*tools)->vector_y;
		printf("calc coords == [%d][%d]\n", (int)(y_cross->x), (int)(y_cross->y));
		printf("y_cross->x = [%f] && y_cross->y = [%f]\n", y_cross->x, y_cross->y);
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

// t_tools	*wall_finder(t_data *data)
// {
// 	double	coord_x;
// 	double	coord_y;
// 	t_tools	*tools;

// 	coord_x = data->p_x;
// 	coord_y = data->p_y;
// 	tools = vector_define(data);
// 	printf("tools->x_cross == [%f] || tools->y_cross == [%f]\n", tools->x_cross->x, tools->x_cross->y);
// 	printf("coordenadas iniciales [%d][%d]\n", (int)coord_x, (int)coord_y);
// 	while (data->map[(int)coord_x][(int)coord_y] != '1')
// 	{
// 		coord_x += tools->x_cross->x * tools->vector_x;
// 		coord_y += tools->x_cross->y * tools->vector_x;
// 		printf("NO hay una pared en [%d][%d]\n", (int)coord_x, (int)coord_y);
// 		printf("valor en el mapa %c\n", data->map[(int)coord_x][(int)coord_y]);
// 	}
// 	tools->x_cross->x = coord_x;
// 	tools->x_cross->y = coord_y;
// 	printf("hay una pared en [%d][%d]\n", (int)coord_x, (int)coord_y);
// 	return (tools);
// }

// float	calc_distance(t_data *data, t_tools *tools)
// {
// 	float	x_distance;
// 	float	y_distance;

	
// }