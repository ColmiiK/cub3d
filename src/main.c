#include <cub3d.h>

int main(int ac, char **av)
{
	t_data data;
	if (ac != 2)
		return (ft_error("Invalid number of arguments"));

	if (ft_parse_map(&data, av[1]))
		return (1);
	

}
