#include <cub3d.h>

int	ft_paint_txt(t_tools *tools, mlx_texture_t *tex, double draw_cross, int y)
{
	//draw_cross == 1.34567890
	//x == 0.66
	(void)tools;
	double x;
	double x_pos;


	x = (int)draw_cross + 1 - draw_cross;

	// printf("x %f\n", x);
	// printf("x * width == %f\n", x * tex->width);
	// printf("y == %d\n", y);
	x_pos = (x * tex->width) + (y * tex->width);
	// printf("-> %f\n", x_pos);

	// printf("-> %d\n", tex->texture.width * tex->texture.height);
	// return (r << 24 | g << 16 | b << 8 | a)

	// printf("%d\n", tex->width * tex->height);
	// printf("%f\n", x_pos);
	return (tex->pixels[(int)x_pos] << 24 | tex->pixels[(int)x_pos + 1] << 16 | tex->pixels[(int)x_pos + 2] << 8 | tex->pixels[(int)x_pos + 3]);


}
