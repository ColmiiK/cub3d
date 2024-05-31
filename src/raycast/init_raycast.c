#include <cub3d.h>

t_tools	*vector_define(t_data *data)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		return (NULL);
	tools->vector_x = 1;
	tools->vector_y = 1;
	tools->x_cross = 1 / tan(data->p_a);
	tools->y_cross = tan(data->p_a);
	printf("tools->x_cross == [%f] || tools->y_cross == [%f]\n", tools->x_cross, tools->y_cross);
	if (tools->x_cross >= __DBL_MAX__)
		tools->x_cross = 1;
	if (tools->y_cross >= __DBL_MAX__)
		tools->y_cross = 1;
	if (data->p_a >= 0 && data->p_a < 180)
		tools->vector_y = -1;
	if (data->p_a >= 90 && data->p_a < 270)
		tools->vector_x = -1;
	return (tools);
}

t_tools	*wall_finder(t_data *data)
{
	double	coord_x;
	double	coord_y;
	t_tools	*tools;

	coord_x = data->p_x;
	coord_y = data->p_y;
	tools = vector_define(data);
	printf("tools->x_cross == [%f] || tools->y_cross == [%f]\n", tools->x_cross, tools->y_cross);
	printf("coordenadas iniciales [%d][%d]\n", (int)coord_x, (int)coord_y);
	while (data->map[(int)coord_x][(int)coord_y] != '1')
	{
		coord_x += tools->x_cross * tools->vector_x;
		coord_y += tools->y_cross * tools->vector_y;
		printf("NO hay una pared en [%d][%d]\n", (int)coord_x, (int)coord_y);
		printf("valor en el mapa %c\n", data->map[(int)coord_x][(int)coord_y]);
	}
	tools->x_cross = coord_x;
	tools->y_cross = coord_y;
	printf("hay una pared en [%d][%d]\n", (int)coord_x, (int)coord_y);
	return (tools);
}

// float	calc_distance(t_data *data, t_tools *tools)
// {
// 	float	x_distance;
// 	float	y_distance;

	
// }