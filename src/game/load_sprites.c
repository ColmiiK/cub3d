#include <cub3d.h>

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
	return (0);
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
	mlx_image_to_window(data->mlx, data->texture->i_sprite[0],
		(W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[1],
		(W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[2],
		(W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[3],
		(W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, data->texture->i_sprite[4],
		(W_WIDTH / 2) - 256, W_HEIGHT - 512);
	data->texture->i_sprite[0]->enabled = true;
	data->texture->i_sprite[1]->enabled = false;
	data->texture->i_sprite[2]->enabled = false;
	data->texture->i_sprite[3]->enabled = false;
	data->texture->i_sprite[4]->enabled = false;
}
