/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:21:30 by albagar4          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	ft_draw_walls(t_data *data, int x, t_tools *tools)
{
	int	y;
	int	color;
	int	max;

	y = ((W_HEIGHT - tools->wall_size) / 2);
	max = (W_HEIGHT + tools->wall_size) / 2;
	while (y < max)
	{
		if (y > W_HEIGHT / 50 && x > W_HEIGHT / 50
			&& y < W_HEIGHT / 50 * 8.2 && x < W_HEIGHT / 50 * 8.2)
			;
		else if (y < W_HEIGHT && y > 0)
		{
			color = ft_paint_txt(tools->orientation, tools->draw_cross,
					y - ((W_HEIGHT - tools->wall_size) / 2), tools);
			mlx_put_pixel(data->wall, x, y, color);
		}
		y++;
	}
}

void	*ray_loop(void *param)
{
	t_thread_data *thread_data = param;
	t_data* data = thread_data->data;
	t_tools	*tools;
	double	scale;
	int		width;

	double angle;
	width = thread_data->start;
	scale = rad_convertor((VISION + 0.0) / (W_WIDTH + 0.0));
	if (data->p_a - rad_convertor(30) < 0)
		angle = data->p_a + rad_convertor(330);
	else
		angle = data->p_a - rad_convertor(30);
	angle += scale * width;
	while (width <= thread_data->end)
	{
		tools = wall_distance(data, &angle);
		define_orientation_1(tools, data, &angle);
		ft_draw_walls(data, width, tools);
		if (angle + scale >= 2 * M_PI)
			angle = angle - (2 * M_PI) + scale;
		else
			angle = angle + scale;
		width++;
		free(tools->x_cross);
		free(tools->y_cross);
		free(tools);
	}
	return NULL;
}

