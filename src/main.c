#include <cub3d.h>

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
		return (ft_error("Invalid number of arguments"));
	if (ft_setup_struct(&data))
		return (ft_error("Error while setting up the structure"));
	if (ft_parse_map(&data, av[1]))
		return (1);
	

}
