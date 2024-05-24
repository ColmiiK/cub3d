#include <cub3d.h>

static int ft_extract_map(t_data *data, char **cub)
{
	int	i;

	while (*cub && !(*cub[0] == ' ' || *cub[0] == '1'))
		cub++;
	data->map = malloc(sizeof(char *) * ft_double_ptr_amount(cub) + 1);
	if (!data->map)
		return (1);
	i = -1;
	while (*cub)
	{
		data->map[++i] = ft_strdup(*cub);
		if (!data->map[i])
			return (1);
		cub++;
	}
	data->map[++i] = NULL;
	return (0);
}

int ft_parse_map(t_data *data, char *str)
{
	if (ft_read_cub_file(data, str))
		return (ft_error("unable to read .cub file"));
	if (ft_extract_info(data, data->cub))
		return (ft_error("unable to extract information from .cub file"));
	if (ft_extract_map(data, data->cub))
		return (ft_error("unable to extract map information from .cub file"));
	if (ft_check_map(data->map))
		return (1);

	return (0);
}
