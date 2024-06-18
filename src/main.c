#include <cub3d.h>

// static void ft_debug_print(t_data data)
// {
// 	printf("\n\t---> .cub file <---\n");
// 	for (int i = 0; data.cub[i]; i++)
// 		printf("%s\n", data.cub[i]);
// 	printf("\nCeiling color: \t%d\nFloor color: \t%d\n", data.texture->ceiling, data.texture->floor);
// 	printf("\nNorth texture: \t%p\n", data.texture->north);
// 	printf("South texture: \t%p\n", data.texture->south);
// 	printf("East texture: \t%p\n", data.texture->east);
// 	printf("West texture: \t%p\n", data.texture->west);
// 	printf("\nPlayer x: \t%f\n", data.p_x);
// 	printf("Player y: \t%f\n", data.p_y);
// 	printf("Player angle: \t%f\n", data.p_a);
// 	printf("\nWidth: \t\t%d\n", data.width);
// 	printf("Height: \t%d\n", data.height);
// }

static int	ft_setup_struct(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_tex));
	data->m_x = 0;
	data->m_y = 0;
	data->frame = 0;
	data->shooting_gun = false;
	data->debug_flag = true;
	if (!data->texture)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_error("Invalid number of arguments"));
	if (ft_setup_struct(&data))
		return (ft_error("Unable to set up main structure"));
	if (ft_parse_map(&data, av[1]))
		return (ft_cleanup(data), 1);
	// ft_debug_print(data);
	ft_initialize_mlx(&data);
	ft_cleanup(data);
	return (0);
}
