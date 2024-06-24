#include <cub3d.h>

static int	ft_extract_map(t_data *data, char **cub)
{
	int	i;

	while (*cub && !(*cub[0] == ' ' || *cub[0] == '1'))
		cub++;
	data->map = ft_calloc(sizeof(char *), ft_double_ptr_amount(cub) + 1);
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

static int	ft_copy_ppos(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
		|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
	{
		data->p_x = j + 0.5;
		data->p_y = i + 0.5;
		if (data->map[i][j] == 'N')
			data->p_a = rad_convertor(270);
		if (data->map[i][j] == 'S')
			data->p_a = rad_convertor(90);
		if (data->map[i][j] == 'E')
			data->p_a = rad_convertor(0);
		if (data->map[i][j] == 'W')
			data->p_a = rad_convertor(180);
		return (0);
	}
	return (1);
}

static void	ft_obtain_ppos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_copy_ppos(data, i, j))
				return ;
		}
	}
}

int	ft_pad_map(t_data *data)
{
	char	*temp;
	int		i;

	i = -1;
	while (data->map[++i])
	{
		if (ft_strlen(data->map[i]) != (unsigned int)data->width)
		{
			temp = (char *)malloc(sizeof(char)
					* (data->width - ft_strlen(data->map[i]) + 1));
			if (!temp)
				return (1);
			temp = ft_memset(temp, ' ', ft_strlen(temp) - 1);
			temp[ft_strlen(temp) - 1] = 0;
			data->map[i] = ft_strjoin_ex(data->map[i], temp, 3);
		}
	}
	return (0);
}

int	ft_parse_map(t_data *data, char *str)
{
	if (ft_read_cub_file(data, str))
		return (ft_error("Unable to read .cub file"));
	if (ft_extract_info(data, data->cub))
		return (ft_error("Unable to extract information from .cub file"));
	if (ft_extract_sprites(data))
		return (ft_error("Unable to load sprites"));
	if (ft_extract_map(data, data->cub))
		return (ft_error("Unable to extract map information from .cub file"));
	ft_obtain_ppos(data, data->map);
	data->height = ft_double_ptr_amount(data->map);
	data->width = ft_check_longest_line(data->map);
	if (ft_check_map(data->map))
		return (1);
	if (ft_pad_map(data))
		return (1);
	return (0);
}
