#include <cub3d.h>

void	init_stats(t_data *data)
{
	t_tools	*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		return ;
	tools->vector_x = 1;
	tools->vector_y = 1;
	if (data->p_a >= 0 && data->p_a < 180)
		tools->vector_y = -1;
	if (data->p_a >= 90 && data->p_a < 270)
		tools->vector_x = -1;
}
