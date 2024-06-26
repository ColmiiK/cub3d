/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_defines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:23 by albagar4          #+#    #+#             */
/*   Updated: 2024/06/26 15:51:16 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	define_orientation_2(t_tools *tools, t_data *data)
{
	double	beta;

	beta = (data->angle - data->p_a);
	tools->distance_x = (tools->distance_x * (fabs)(cos(beta)));
	tools->wall_size = (int)(900 / tools->distance_x);
	if (tools->vector_y < 0)
		tools->orientation = data->texture->north;
	else
	{
		tools->flag = 1;
		tools->orientation = data->texture->south;
	}
	tools->draw_cross = tools->x_cross->x;
}

void	define_orientation_1(t_tools *tools, t_data *data)
{
	double	beta;

	beta = (data->angle - data->p_a);
	if ((tools->distance_y > 0 && tools->distance_x > tools->distance_y)
		|| tools->distance_x <= 0)
	{
		tools->distance_y = (tools->distance_y * (fabs)(cos(beta)));
		tools->wall_size = (int)(900 / tools->distance_y);
		if (tools->vector_x < 0)
		{
			tools->flag = 1;
			tools->orientation = data->texture->west;
		}
		else
			tools->orientation = data->texture->east;
		tools->draw_cross = tools->y_cross->y;
	}
	else
		define_orientation_2(tools, data);
}

double	x_distance(t_data *data)
{
	double	distance_x;

	if ((fabs)(1 / tan(data->angle)) == 0)
		distance_x = -1;
	else
		distance_x = (fabs)(1 / tan(data->angle));
	return (distance_x);
}

double	y_distance(t_data *data)
{
	double	distance_y;

	if ((fabs)(tan(data->angle)) == 0)
		distance_y = -1;
	else
		distance_y = (fabs)(tan(data->angle));
	return (distance_y);
}

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
	tools->flag = 1;
	if (!(data->angle >= 0 && data->angle <= M_PI))
		tools->vector_y = -1;
	if (data->angle >= rad_convertor(90)
		&& data->angle <= rad_convertor(270))
		tools->vector_x = -1;
	return (tools);
}
