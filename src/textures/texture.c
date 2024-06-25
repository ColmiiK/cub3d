#include <cub3d.h>

int ft_paint_txt(mlx_texture_t *tex, double draw_cross, int y, int wall_size)
{
	int	x;
	int	y_pos;
	int	pos;
	double scale;


	scale = (tex->height + 0.0) / (wall_size + 0.0);
	// printf("-> %f\n", scale);
	x = draw_cross * tex->width; // Horizontal position of the texture
	y_pos = (int)(scale * y) * tex->width; // Vertical position of the texture
	pos = (y_pos + x) * tex->bytes_per_pixel; // Actual position of the texture (How many sizeof(int) steps are needed to reach the position in the array)
	if (pos < 0 || pos + 3 >= (int)(tex->width * tex->height * 4)) // Protection if the position is not valid
		return (0);
	return ((tex->pixels[pos] << 24)
		| (tex->pixels[pos + 1] << 16)
		| (tex->pixels[pos + 2] << 8)
		| tex->pixels[pos + 3]); // Return the color data with bitwise operations
}
