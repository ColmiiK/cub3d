/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:25:51 by albagar4          #+#    #+#             */
/*   Updated: 2024/06/26 16:30:41 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	ft_paint_txt(mlx_texture_t *tex, double draw_cross, int y, t_tools *tools)
{
	int		x;
	int		y_pos;
	int		pos;
	double	scale;

	scale = (tex->height + 0.0) / (tools->wall_size + 0.0);
	x = (draw_cross - (int)draw_cross) * tex->width;
	if (tools->flag == 1)
		x = tex->width - x;
	y_pos = (int)(scale * y) *tex->width;
	pos = (y_pos + x) * tex->bytes_per_pixel;
	if (pos < 0 || pos + 3 >= (int)(tex->width * tex->height * 4))
		return (0);
	return ((tex->pixels[pos] << 24)
		| (tex->pixels[pos + 1] << 16)
		| (tex->pixels[pos + 2] << 8)
		| tex->pixels[pos + 3]);
}
