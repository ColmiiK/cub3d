#include <cub3d.h>

double	x_distance(t_data *data)
{
	double	distance_x;

	if ((fabs)(1 / tan(data->p_a)) == 0
		|| (fabs)(1 / tan(data->p_a)) >= INT32_MAX)
		distance_x = 1;
	else
		distance_x = (fabs)(1 / tan(data->p_a));
	return (distance_x);
}

double	y_distance(t_data *data)
{
	double	distance_y;

	if ((fabs)(tan(data->p_a)) == 0
		|| (fabs)(tan(data->p_a)) >= INT32_MAX)
		distance_y = 1;
	else
		distance_y = (fabs)(tan(data->p_a));
	return (distance_y);
}

double	rad_convertor(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

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

t_coord	*first_step_x(t_data *data, t_tools *tools)
{
	t_coord	*first_x;
	t_coord	*init;
	double	distance;

	first_x = malloc(sizeof(t_coord));
	init = malloc(sizeof(t_coord));
	if (!init || !first_x)
		return (NULL);
	init->x = data->p_x;
	init->y = data->p_y;
	first_x->y = (int)(data->p_y);
	if (data->p_a > 0 && data->p_a < M_PI)
		first_x->y += 1;
	distance = (fabs)(first_x->y - data->p_y);
	first_x->x = distance / tan(data->p_a);
	first_x->x = data->p_x + (first_x->x * tools->vector_y);
	if (ft_delimiter(data, first_x) == 1)
		return(init);
	return (first_x);
}

t_coord	*first_step_y(t_data *data, t_tools *tools)
{
	t_coord	*first_y;
	t_coord	*init;
	double	distance;

	first_y = malloc(sizeof(t_coord));
	init = malloc(sizeof(t_coord));
	if (!first_y || !init)
		return (NULL);
	init->x = data->p_x;
	init->y = data->p_y;
	first_y->x = (int)(data->p_x);
	if (!(data->p_a > rad_convertor(90)
			&& data->p_a < rad_convertor(270)))
		first_y->x += 1;
	distance = (fabs)(first_y->x - data->p_x);
	first_y->y = distance * tan(data->p_a);
	first_y->y = data->p_y + (first_y->y * tools->vector_x);
	if (ft_delimiter(data, first_y) == 1)
		return (init);
	return (first_y);
}
