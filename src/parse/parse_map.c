#include <cub3d.h>

int ft_read_cub_file(t_data *data, char *str)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	temp = ft_strdup("");
	if (!temp)
		return (1);
	while (line)
	{
		temp = ft_strjoin_ex(temp, line, 3);
		line = get_next_line(fd);
	}
	data->cub = ft_split(temp, '\n');
	free(temp);
	return (0);
}

mlx_texture_t *ft_save_texture(char *route)
{
	while (*route == ' ')
		route++;
	return (mlx_load_png(route));
}

int ft_check_textures(t_tex *textures)
{
	if (!textures->north)
		return (1);
	if (!textures->south)
		return (1);
	if (!textures->east)
		return (1);
	if (!textures->west)
		return (1);
	return (0);
}

int ft_save_c_f(char *colors)
{
	char	**temp;
	int		rgb[3];

	temp = ft_split(colors, ',');
	if (ft_double_ptr_amount(temp) != 3)
		return (0);
	rgb[0] = ft_atoi(temp[0]);
	rgb[1] = ft_atoi(temp[1]);
	rgb[2] = ft_atoi(temp[2]);
	ft_clean_double_ptr(temp);
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 255);
}

int ft_extract_info(t_data *data, char **cub)
{
	int i;

	i = -1;
	while (cub[++i])
	{
		if (!ft_strncmp(cub[i], "NO", 2))
			data->texture->north = ft_save_texture(cub[i] + 2);
		if (!ft_strncmp(cub[i], "SO", 2))
			data->texture->south = ft_save_texture(cub[i] + 2);
		if (!ft_strncmp(cub[i], "WE", 2))
			data->texture->west = ft_save_texture(cub[i] + 2);
		if (!ft_strncmp(cub[i], "EA", 2))
			data->texture->east = ft_save_texture(cub[i] + 2);
		if (!ft_strncmp(cub[i], "F", 1))
			data->texture->floor = ft_save_c_f(cub[i] + 1);
		if (!ft_strncmp(cub[i], "C", 1))
			data->texture->ceiling = ft_save_c_f(cub[i] + 1);
	}
	if (ft_check_textures(data->texture))
		return (1);
	if (data->texture->floor == 0 || data->texture->ceiling == 0)
		return (1);
	return (0);
}

int ft_parse_map(t_data *data, char *str)
{
	if (ft_read_cub_file(data, str))
		return (ft_error("Unable to read .cub file"));
	if (ft_extract_info(data, data->cub))
		return (ft_error("Unable to extract information from .cub file"));
	

	// for (int i = 0; data->cub[i]; i++)
	// 	printf("-> %s\n", data->cub[i]);
	return (0);
}
