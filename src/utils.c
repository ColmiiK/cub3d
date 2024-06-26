/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:16 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 16:10:04 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_check_longest_line(char **map)
{
	int	biggest;
	int	new;

	biggest = 0;
	while (*map)
	{
		new = ft_strlen(*map);
		if (new > biggest)
			biggest = new;
		map++;
	}
	return (biggest);
}

void	ft_fill_square(int color, mlx_image_t *minimap, int x, int y)
{
	int	len_x;
	int	len_y;

	len_x = x + W_HEIGHT / 50;
	len_y = y + W_HEIGHT / 50;
	while (y <= len_y)
	{
		x = len_x - W_HEIGHT / 50;
		while (x <= len_x)
			mlx_put_pixel(minimap, x++, y, color);
		y++;
	}
}
