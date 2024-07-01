/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:22 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

static void	ft_cleanup_gun(t_data data)
{
	if (data.texture->sprite[0])
		mlx_delete_texture(data.texture->sprite[0]);
	if (data.texture->sprite[1])
		mlx_delete_texture(data.texture->sprite[1]);
	if (data.texture->sprite[2])
		mlx_delete_texture(data.texture->sprite[2]);
	if (data.texture->sprite[3])
		mlx_delete_texture(data.texture->sprite[3]);
	if (data.texture->sprite[4])
		mlx_delete_texture(data.texture->sprite[4]);
	if (data.texture->sprite[5])
		mlx_delete_texture(data.texture->sprite[5]);
	if (data.texture->sprite[6])
		mlx_delete_texture(data.texture->sprite[6]);
	if (data.texture->sprite[7])
		mlx_delete_texture(data.texture->sprite[7]);
	if (data.texture->sprite[8])
		mlx_delete_texture(data.texture->sprite[8]);
	if (data.texture->sprite[9])
		mlx_delete_texture(data.texture->sprite[9]);
	if (data.texture->sprite[10])
		mlx_delete_texture(data.texture->sprite[10]);
	if (data.texture->sprite[11])
		mlx_delete_texture(data.texture->sprite[11]);
}

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
	ft_cleanup_gun(data);
	free(data.texture);
	if (data.cub)
		ft_clean_double_ptr(data.cub);
	if (data.map)
		ft_clean_double_ptr(data.map);
}
