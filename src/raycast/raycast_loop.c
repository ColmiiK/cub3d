#include <cub3d.h>

void	ft_draw_walls(t_data *data, int x, t_tools *tools)
{
	int	y;

	y = ((W_HEIGHT - tools->wall_size) / 2);
	while (y < ((W_HEIGHT + tools->wall_size) / 2))
	{
		if (x >= W_WIDTH)
			break;
		if (y >= W_HEIGHT)
			break;
		mlx_put_pixel(data->wall, abs(x), abs(y), tools->orientation);
		y++;
	}
}

// Draws a line on the minimap in the angle of the player
void ft_draw_line(t_data *data, t_tools *tools)
{
    int x0 = 90;
    int y0 = 90;
	int x1;
	int y1;
	if (tools->distance_x < tools->distance_y)
	{
		x1 = x0 + (int)(tools->distance_x * 20 * cos(data->p_a));
		y1 = y0 + (int)(tools->distance_x * 20 * sin(data->p_a));
	} else {
		x1 = x0 + (int)(tools->distance_y * 20 * cos(data->p_a));
		y1 = y0 + (int)(tools->distance_y * 20 * sin(data->p_a));
	}
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;
    while (1)
    {
		mlx_put_pixel(data->line, abs(x0), abs(y0), RED);
		
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

// Prototype of the loop that will shoot one ray per coordinate
// and draw the needed line
void	ray_loop(t_data *data)
{
	t_tools	*tools;
	double	scale;
	int		width;

	width = 0;
	scale = rad_convertor(0.09);
	if (data->p_a - rad_convertor(45) < 0)
		data->angle = data->p_a + rad_convertor(315);
	else
		data->angle = data->p_a - rad_convertor(45);
	while (width <= W_WIDTH)
	{
		tools = wall_distance(data);
		define_orientation(tools);
		ft_draw_walls(data, width, tools);
		if (width == 500)
			ft_draw_line(data, tools);
		if (data->angle + scale >= 2 * M_PI)
			data->angle = data->angle - (2 * M_PI) + scale;
		else
			data->angle = data->angle + scale;
		width++;
	}
		
}
