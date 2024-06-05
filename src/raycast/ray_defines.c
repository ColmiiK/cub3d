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

t_coord	*first_step_x(t_data *data, t_tools *tools)
{
	t_coord	*first_x;
	double	distance;

	first_x = malloc(sizeof(t_coord));
	if (!first_x)
		return (NULL);
	first_x->y = (int)(data->p_y);
	if (data->p_a > 0 && data->p_a < 180)
		first_x->y += 1;
	distance = (fabs)(first_x->y - data->p_y);
	first_x->x = distance / tan(data->p_a);
	first_x->x = data->p_x + (first_x->x * tools->vector_x);
	printf("\n\t\tsaliendo del first_step_x:\n");
	printf("\t\tfirst_x->x = %f\n\t\tfirst_x->y = %f\n\n", first_x->x, first_x->y);
	return (first_x);
}

t_coord	*first_step_y(t_data *data, t_tools *tools)
{
	t_coord	*first_y;
	double	distance;

	first_y = malloc(sizeof(t_coord));
	if (!first_y)
		return (NULL);
	first_y->x = (int)(data->p_x);
	if (!(data->p_a > 90 && data->p_a < 270))
		first_y->x += 1;
	distance = (fabs)(first_y->x - data->p_x);
	first_y->y = distance * tan(data->p_a);
	first_y->y = data->p_y + (first_y->y * tools->vector_y);
	printf("\n\t\tsaliendo del first_step_y:\n");
	printf("\t\tfirst_y->x = %f\n\t\tfirst_y->y = %f\n\n", first_y->x, first_y->y);
	return (first_y);
}
