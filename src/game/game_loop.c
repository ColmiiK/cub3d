#include <cub3d.h>

void ft_put_sprites(t_data *data, t_tex *t)
{
	mlx_image_to_window(data->mlx, t->i_sprite[0], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[1], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[2], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[3], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[4], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[5], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[6], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[7], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[8], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[9], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[10], W_WIDTH / 2, W_HEIGHT - 300);
	mlx_image_to_window(data->mlx, t->i_sprite[11], W_WIDTH / 2, W_HEIGHT - 300);
	t->i_sprite[0]->enabled = true;
	t->i_sprite[1]->enabled = false;
	t->i_sprite[2]->enabled = false;
	t->i_sprite[3]->enabled = false;
	t->i_sprite[4]->enabled = false;
	t->i_sprite[5]->enabled = false;
	t->i_sprite[6]->enabled = false;
	t->i_sprite[7]->enabled = false;
	t->i_sprite[8]->enabled = false;
	t->i_sprite[9]->enabled = false;
	t->i_sprite[10]->enabled = false;
	t->i_sprite[11]->enabled = false;
}
static int ft_load_sprites(t_data *data)
{
	data->texture->sprite[0] = mlx_load_png("./textures/gun/f0.png");
	data->texture->sprite[1] = mlx_load_png("./textures/gun/f1.png");
	data->texture->sprite[2] = mlx_load_png("./textures/gun/f2.png");
	data->texture->sprite[3] = mlx_load_png("./textures/gun/f3.png");
	data->texture->sprite[4] = mlx_load_png("./textures/gun/f4.png");
	data->texture->sprite[5] = mlx_load_png("./textures/gun/f5.png");
	data->texture->sprite[6] = mlx_load_png("./textures/gun/f6.png");
	data->texture->sprite[7] = mlx_load_png("./textures/gun/f7.png");
	data->texture->sprite[8] = mlx_load_png("./textures/gun/f8.png");
	data->texture->sprite[9] = mlx_load_png("./textures/gun/f9.png");
	data->texture->sprite[10] = mlx_load_png("./textures/gun/f10.png");
	data->texture->sprite[11] = mlx_load_png("./textures/gun/f11.png");
	data->texture->i_sprite[0] = mlx_texture_to_image(data->mlx, data->texture->sprite[0]);
	data->texture->i_sprite[1] = mlx_texture_to_image(data->mlx, data->texture->sprite[1]);
	data->texture->i_sprite[2] = mlx_texture_to_image(data->mlx, data->texture->sprite[2]);
	data->texture->i_sprite[3] = mlx_texture_to_image(data->mlx, data->texture->sprite[3]);
	data->texture->i_sprite[4] = mlx_texture_to_image(data->mlx, data->texture->sprite[4]);
	data->texture->i_sprite[5] = mlx_texture_to_image(data->mlx, data->texture->sprite[5]);
	data->texture->i_sprite[6] = mlx_texture_to_image(data->mlx, data->texture->sprite[6]);
	data->texture->i_sprite[7] = mlx_texture_to_image(data->mlx, data->texture->sprite[7]);
	data->texture->i_sprite[8] = mlx_texture_to_image(data->mlx, data->texture->sprite[8]);
	data->texture->i_sprite[9] = mlx_texture_to_image(data->mlx, data->texture->sprite[9]);
	data->texture->i_sprite[10] = mlx_texture_to_image(data->mlx, data->texture->sprite[10]);
	data->texture->i_sprite[11] = mlx_texture_to_image(data->mlx, data->texture->sprite[11]);
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
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (0);
}
