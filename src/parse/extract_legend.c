/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_legend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:17:53 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 12:07:08 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static mlx_texture_t	*ft_save_texture(char *route)
{
	while (*route == ' ')
		route++;
	return (mlx_load_png(route));
}

static int	ft_check_textures(t_tex *textures)
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

static int ft_check_c_f(int *rgb, char **str)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < 3)
	{
		temp = ft_itoa(rgb[i]);
		if (ft_strcmp(temp, str[i]))
			return (free(temp), 1);
		free(temp);
	}
	if (!(rgb[0] >= 0 && rgb[0] < 256)
		|| !(rgb[1] >= 0 && rgb[1] < 256)
		|| !(rgb[2] >= 0 && rgb[2] < 256))
		return (1);
	return (0);
}

static int	ft_save_c_f(char *colors)
{
	char	**temp;
	int		rgb[3];

	while (*colors == ' ')
		colors++;
	temp = ft_split(colors, ',');
	if (ft_double_ptr_amount(temp) != 3)
	{
		ft_clean_double_ptr(temp);
		return (0);
	}
	rgb[0] = ft_atoi(temp[0]);
	rgb[1] = ft_atoi(temp[1]);
	rgb[2] = ft_atoi(temp[2]);
	if (ft_check_c_f(rgb, temp))
		return (0);
	ft_clean_double_ptr(temp);
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 255);
}

int	ft_extract_info(t_data *data, char **cub)
{
	int	i;

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
	if (ft_check_textures(data->texture)
		|| data->texture->floor == 0 || data->texture->ceiling == 0)
	{
		data->map = ft_split(" ", ' ');
		return (1);
	}
	return (0);
}
