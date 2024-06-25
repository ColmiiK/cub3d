/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:25:51 by albagar4          #+#    #+#             */
/*   Updated: 2024/06/25 17:29:47 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_paint_txt(mlx_texture_t *tex, double draw_cross, int y, int wall_size)
{
	int		x;
	int		y_pos;
	int		pos;
	double	scale;

	scale = (tex->height + 0.0) / (wall_size + 0.0);
	x = (draw_cross - (int)draw_cross) * tex->width;
	y_pos = (int)(scale * y) *tex->width;
	pos = (y_pos + x) * tex->bytes_per_pixel;
	if (pos < 0 || pos + 3 >= (int)(tex->width * tex->height * 4))
		return (0);
	return ((tex->pixels[pos] << 24)
		| (tex->pixels[pos + 1] << 16)
		| (tex->pixels[pos + 2] << 8)
		| tex->pixels[pos + 3]);
}
