/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:32 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:51:00 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3D", false);
	if (!data->mlx)
		return (1);
	ft_draw_game(data);
	mlx_loop_hook(data->mlx, &ft_hook, data);
	mlx_key_hook(data->mlx, &ft_keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
