#include <cub3d.h>

// Converts degrees to radians
double	rad_convertor(double deg)
{
	double	rad;

	rad = deg * (M_PI / 180);
	return (rad);
}

// Checks if the calculated valued is out of the correct range
int	ft_delimiter(t_data *data, t_coord *cross)
{
	if (cross->x <= 0 || cross->x >= data->width
		|| cross->y <= 0 || cross->y >= data->height)
		return (1);
	return (0);
}