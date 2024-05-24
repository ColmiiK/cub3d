#include <cub3d.h>

void ft_debug_print(t_data data)
{
	printf("\n\t---> .cub file <---\n");
	for (int i = 0; data.cub[i]; i++)
		printf("%s\n", data.cub[i]);
	printf("\nCeiling color: \t%d\nFloor color: \t%d\n", data.texture->ceiling, data.texture->floor);
	printf("\nNorth texture: \t%p\n", data.texture->north);
	printf("South texture: \t%p\n", data.texture->south);
	printf("East texture: \t%p\n", data.texture->east);
	printf("West texture: \t%p\n", data.texture->west);

	printf("\n\t---> map <---\n");
	for (int i = 0; data.map[i]; i++)
		printf("%s\n", data.map[i]);
}

int ft_setup_struct(t_data *data)
{
	data->mlx = malloc(sizeof(mlx_t));
	data->texture = malloc(sizeof(t_tex));
	if (!data->texture)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	t_data data;
	if (ac != 2)
		return (ft_error("invalid number of arguments"));
	if (ft_setup_struct(&data))
		return (ft_error("unable to set up main structure"));
	if (ft_parse_map(&data, av[1]))
		return (1);
	
	ft_debug_print(data);
	

}
