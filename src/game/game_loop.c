#include <cub3d.h>

void ft_put_sprites(t_data *data, t_tex *t)
{
	mlx_image_to_window(data->mlx, t->i_sprite[0], (W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, t->i_sprite[1], (W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, t->i_sprite[2], (W_WIDTH / 2) - 256,W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, t->i_sprite[3], (W_WIDTH / 2) - 256, W_HEIGHT - 512);
	mlx_image_to_window(data->mlx, t->i_sprite[4], (W_WIDTH / 2) - 256, W_HEIGHT - 512);
	t->i_sprite[0]->enabled = true;
	t->i_sprite[1]->enabled = false;
	t->i_sprite[2]->enabled = false;
	t->i_sprite[3]->enabled = false;
	t->i_sprite[4]->enabled = false;
}

static int ft_load_sprites(t_data *data)
{
	data->texture->sprite[0] = mlx_load_png("./textures/gun/f0.png");
	data->texture->sprite[1] = mlx_load_png("./textures/gun/f1.png");
	data->texture->sprite[2] = mlx_load_png("./textures/gun/f2.png");
	data->texture->sprite[3] = mlx_load_png("./textures/gun/f3.png");
	data->texture->sprite[4] = mlx_load_png("./textures/gun/f4.png");
	data->texture->i_sprite[0] = mlx_texture_to_image(data->mlx, data->texture->sprite[0]);
	data->texture->i_sprite[1] = mlx_texture_to_image(data->mlx, data->texture->sprite[1]);
	data->texture->i_sprite[2] = mlx_texture_to_image(data->mlx, data->texture->sprite[2]);
	data->texture->i_sprite[3] = mlx_texture_to_image(data->mlx, data->texture->sprite[3]);
	data->texture->i_sprite[4] = mlx_texture_to_image(data->mlx, data->texture->sprite[4]);
	ft_put_sprites(data, data->texture);
	return (0);
}

int	ft_initialize_mlx(t_data *data)
{
	data->mlx = mlx_init(W_WIDTH, W_HEIGHT, "cub3d", false);
	data->game_img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	if (!data->mlx)
		return (1);
	ft_draw_game(data);
	if (ft_load_sprites(data))
		return (1);
	printf("p_a == %f\n", data->p_a);
	mlx_loop_hook(data->mlx, &ft_hook, data);
	mlx_mouse_hook(data->mlx, &ft_mousehook, data);
	mlx_key_hook(data->mlx, &ft_keyhook, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
