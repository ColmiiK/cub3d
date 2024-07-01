/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:40 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = (int)data->p_x;
	y = (int)data->p_y;
	if (keydata.key == MLX_KEY_Q && keydata.action == MLX_PRESS)
		data->debug_flag = !data->debug_flag;
}
