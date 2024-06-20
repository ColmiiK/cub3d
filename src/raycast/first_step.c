#include <cub3d.h>

// Depending on the angle we're going to calculate the
// first coordinates in which coord_y is an entire number
t_coord	*first_step_x(t_data *data, t_tools *tools)
{
	t_coord	*first_x;
	t_coord	*init;
	double	distance;

	init = malloc(sizeof(t_coord));
	first_x = malloc(sizeof(t_coord));
	if (!init || !first_x)
		return (NULL);
	init->x = data->p_x;
	init->y = data->p_y;
	first_x->y = (int)data->p_y;
	if (tools->vector_y == 1)
		first_x->y += 1;
	distance = (fabs)(data->p_y - first_x->y);
	first_x->x = distance / (fabs)(tan(data->angle));
	first_x->x = data->p_x + (first_x->x * tools->vector_x);
	if (ft_delimiter(data, first_x) == 1 || distance == 0)
		return (init);
	if (first_x->y < 0 || first_x->x < 0)
		printf("first_x->x == %f && first_x->y == %f\n", first_x->x, first_x->y);
	return (first_x);
}

// Depending on the angle we're going to calculate the
// first coordinates in which coord_x is an entire number
t_coord	*first_step_y(t_data *data, t_tools *tools)
{
	t_coord	*first_y;
	t_coord	*init;
	double	distance;

	init = malloc(sizeof(t_coord));
	first_y = malloc(sizeof(t_coord));
	if (!init || !first_y)
		return (NULL);
	init->x = data->p_x;
	init->y = data->p_y;
	first_y->x = (int)data->p_x;
	if (tools->vector_x == 1)
		first_y->x += 1;
	distance = (fabs)(data->p_x - first_y->x);
	if (distance == 0)
		return (init);
	first_y->y = distance * (fabs)(tan(data->angle));
	first_y->y = data->p_y + (first_y->y * tools->vector_y);
	if (ft_delimiter(data, first_y) == 1 || distance == 0)
		return (init);
	if (first_y->x < 0 || first_y->y < 0)
		printf("first_y->x == %f && first_y->y == %f\n", first_y->x, first_y->y);
	return (first_y);
}
