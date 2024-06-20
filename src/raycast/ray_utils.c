#include <cub3d.h>

int	ft_isanint(double nbr)
{
	if (nbr - (int)nbr == 0.0000)
		return (0);
	return (1);
}

// Converts degrees to radians
inline double	rad_convertor(double deg)
{
	return (deg * (M_PI / 180));
}

// Checks if the calculated valued is out of the correct range
int	ft_delimiter(t_data *data, t_coord *cross)
{
	if (cross->x <= 0 || cross->x >= data->width
		|| cross->y <= 0 || cross->y >= data->height)
		return (1);
	return (0);
}