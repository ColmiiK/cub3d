/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:19:49 by albagar4          #+#    #+#             */
/*   Updated: 2024/06/26 16:24:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

t_coord	*x_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*x_cross;

	x_cross = first_step_x(data, tools);
	tools->distance_x = x_distance(data);
	while (x_cross->x >= 0 && x_cross->x < data->width && x_cross->y >= 0
		&& x_cross->y < data->height)
	{
		if ((int)x_cross->y > 0
			&& (data->map[(int)x_cross->y - 1][(int)x_cross->x] == '1'
			|| data->map[(int)x_cross->y - 1][(int)x_cross->x] == ' ')
			&& tools->vector_y == -1)
			break ;
		else if (data->map[(int)x_cross->y][(int)x_cross->x] == '1'
			|| data->map[(int)x_cross->y][(int)x_cross->x] == ' ')
			break ;
		else
		{
			if (tools->distance_x != -1)
				x_cross->x += (tools->distance_x * tools->vector_x);
			x_cross->y += tools->vector_y;
		}
	}
	return (x_cross);
}

t_coord	*y_wall_finder(t_data *data, t_tools *tools)
{
	t_coord	*y_cross;

	y_cross = first_step_y(data, tools);
	tools->distance_y = y_distance(data);
	while ((y_cross->y >= 0 && y_cross->y <= data->height)
		&& (y_cross->x >= 0 && y_cross->x <= data->width))
	{
		if ((int)y_cross->x > 0
			&& data->map[(int)y_cross->y][(int)y_cross->x - 1] == '1'
			&& tools->vector_x == -1)
			break ;
		else if (data->map[(int)y_cross->y][(int)y_cross->x] == '1')
			break ;
		else
		{
			if (tools->distance_y != -1)
				y_cross->y += (tools->distance_y * tools->vector_y);
			y_cross->x += tools->vector_x;
		}
	}
	return (y_cross);
}

t_tools	*wall_distance(t_data *data)
{
	t_tools	*tools;

	tools = vector_define(data);
	tools->x_cross = x_wall_finder(data, tools);
	tools->y_cross = y_wall_finder(data, tools);
	if (tools->distance_x != -1)
	{
		tools->distance_x = sqrt(pow(tools->x_cross->x - data->p_x, 2)
				+ pow(tools->x_cross->y - data->p_y, 2));
	}
	if (tools->distance_y != -1)
	{
		tools->distance_y = sqrt(pow(tools->y_cross->x - data->p_x, 2)
				+ pow(tools->y_cross->y - data->p_y, 2));
	}
	return (tools);
}
