/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:28 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:28 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_draw_background(t_data *data)
{
	int	coord_x;
	int	coord_y;

	coord_x = 0;
	while (coord_x < W_WIDTH)
	{
		coord_y = 0;
		while (coord_y < W_HEIGHT)
		{
			if (coord_y < W_HEIGHT / 2)
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->ceiling);
			else
				mlx_put_pixel(data->game_img, coord_x, coord_y,
					data->texture->floor);
			coord_y++;
		}
		coord_x++;
	}
}

void	ft_draw_game(t_data *data)
{
	ft_draw_minimap(data);
	data->game_img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	ft_draw_background(data);
	data->wall = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->line = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	mlx_image_to_window(data->mlx, data->game_img, 0, 0);
	mlx_image_to_window(data->mlx, data->wall, 0, 0);
	mlx_image_to_window(data->mlx, data->line, 0, 0);
}
