#include <cub3d.h>

int	ft_paint_txt(mlx_texture_t *orientation, t_coord *cross, int flag)
{
	static int	i = 0;
	static int	prev_flag = -1;

	(void)cross;
	i = 5;
	if (flag == prev_flag
		&& i <= (int)(orientation->height * orientation->width))
		i += orientation->width * orientation->bytes_per_pixel;
	else
	{
		i = 0;
		prev_flag = flag;
	}
	return (orientation->pixels[i]);
}
