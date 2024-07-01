/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:22 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:28 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	ft_cleanup(t_data data)
{
	if (data.texture->north)
		mlx_delete_texture(data.texture->north);
	if (data.texture->south)
		mlx_delete_texture(data.texture->south);
	if (data.texture->east)
		mlx_delete_texture(data.texture->east);
	if (data.texture->west)
		mlx_delete_texture(data.texture->west);
	free(data.texture);
	if (data.cub)
		ft_clean_double_ptr(data.cub);
	if (data.map)
		ft_clean_double_ptr(data.map);
}
