/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:21:12 by albagar4          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:28 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
