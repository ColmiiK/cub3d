/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:43 by alvega-g          #+#    #+#             */
/*   Updated: 2024/07/01 11:50:38 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D_bonus.h>

static int	ft_extract_sprites_2(t_data *data)
{
	data->texture->sprite[6] = mlx_load_png("./textures/gun/f6.png");
	if (!data->texture->sprite[6])
		return (1);
	data->texture->sprite[7] = mlx_load_png("./textures/gun/f7.png");
	if (!data->texture->sprite[7])
		return (1);
	data->texture->sprite[8] = mlx_load_png("./textures/gun/f8.png");
	if (!data->texture->sprite[8])
		return (1);
	data->texture->sprite[9] = mlx_load_png("./textures/gun/f9.png");
	if (!data->texture->sprite[9])
		return (1);
	data->texture->sprite[10] = mlx_load_png("./textures/gun/f10.png");
	if (!data->texture->sprite[10])
		return (1);
	data->texture->sprite[11] = mlx_load_png("./textures/gun/f11.png");
	if (!data->texture->sprite[11])
		return (1);
	return (0);
}

int	ft_extract_sprites(t_data *data)
{
	data->texture->sprite[0] = mlx_load_png("./textures/gun/f0.png");
	if (!data->texture->sprite[0])
		return (1);
	data->texture->sprite[1] = mlx_load_png("./textures/gun/f1.png");
	if (!data->texture->sprite[1])
		return (1);
	data->texture->sprite[2] = mlx_load_png("./textures/gun/f2.png");
	if (!data->texture->sprite[2])
		return (1);
	data->texture->sprite[3] = mlx_load_png("./textures/gun/f3.png");
	if (!data->texture->sprite[3])
		return (1);
	data->texture->sprite[4] = mlx_load_png("./textures/gun/f4.png");
	if (!data->texture->sprite[4])
		return (1);
	data->texture->sprite[5] = mlx_load_png("./textures/gun/f5.png");
	if (!data->texture->sprite[5])
		return (1);
	if (ft_extract_sprites_2(data))
		return (1);
	return (0);
}

static void	ft_load_sprites_3(t_data *data)
{
	data->texture->i_sprite[0]->enabled = true;
	data->texture->i_sprite[1]->enabled = false;
	data->texture->i_sprite[2]->enabled = false;
	data->texture->i_sprite[3]->enabled = false;
	data->texture->i_sprite[4]->enabled = false;
	data->texture->i_sprite[5]->enabled = false;
	data->texture->i_sprite[6]->enabled = false;
	data->texture->i_sprite[7]->enabled = false;
	data->texture->i_sprite[8]->enabled = false;
	data->texture->i_sprite[9]->enabled = false;
	data->texture->i_sprite[10]->enabled = false;
	data->texture->i_sprite[11]->enabled = false;
}

static void	ft_load_sprites_2(t_data *data)
{
	mlx_image_to_window(data->mlx, data->texture->i_sprite[0],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[1],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[2],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[3],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[4],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[5],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[6],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[7],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[8],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[9],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[10],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[11],
		(W_WIDTH / 2) - 256, W_HEIGHT - 331);
	ft_load_sprites_3(data);
}

void	ft_load_sprites(t_data *data)
{
	data->texture->i_sprite[0] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[0]);
	data->texture->i_sprite[1] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[1]);
	data->texture->i_sprite[2] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[2]);
	data->texture->i_sprite[3] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[3]);
	data->texture->i_sprite[4] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[4]);
	data->texture->i_sprite[5] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[5]);
	data->texture->i_sprite[6] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[6]);
	data->texture->i_sprite[7] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[7]);
	data->texture->i_sprite[8] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[8]);
	data->texture->i_sprite[9] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[9]);
	data->texture->i_sprite[10] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[10]);
	data->texture->i_sprite[11] = mlx_texture_to_image(data->mlx,
			data->texture->sprite[11]);
	ft_load_sprites_2(data);
}
