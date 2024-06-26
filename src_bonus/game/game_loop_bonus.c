/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:32 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:51 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

int	ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (1);
	ft_draw_game(data);
	ft_load_sprites(data);
	mlx_set_mouse_pos(data->mlx, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_loop_hook(data->mlx, &ft_hook, data);
	mlx_mouse_hook(data->mlx, &ft_mousehook, data);
	mlx_key_hook(data->mlx, &ft_keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
