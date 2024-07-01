/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:21 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

void	ft_mousehook(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)mods;
	data = param;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
		data->shooting_gun = true;
}
