#include <cub3d.h>

int ft_cleanup(t_data data)
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
	return (1);
}
