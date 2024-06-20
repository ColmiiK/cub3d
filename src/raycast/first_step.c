#include <cub3d.h>

// Depending on the angle we're going to calculate the
// first coordinates in which coord_y is an entire number
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
	if (data->angle > 0 && data->angle < M_PI)
		first_x->y += 1;
	distance = (fabs)(first_x->y - data->p_y);
	first_x->x = distance / tan(data->angle);
	first_x->x = data->p_x + (first_x->x * tools->vector_y);
	if (ft_delimiter(data, first_x) == 1)
		return (free(first_x), init);
	return (free(init), first_x);
}

// Depending on the angle we're going to calculate the
// first coordinates in which coord_x is an entire number
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
	if (!(data->angle > rad_convertor(90)
			&& data->angle < rad_convertor(270)))
		first_y->x += 1;
	distance = (fabs)(first_y->x - data->p_x);
	first_y->y = distance * tan(data->angle);
	first_y->y = data->p_y + (first_y->y * tools->vector_x);
	if (ft_delimiter(data, first_y) == 1)
		return (free(first_y), init);
	return (free(init), first_y);
}
