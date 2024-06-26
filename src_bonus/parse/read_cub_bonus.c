/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:18:07 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:51 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static int	ft_cleanup_empty_utils(t_data *data, char **str)
{
	data->cub = ft_split(" ", ' ');
	data->map = ft_split(" ", ' ');
	free(*str);
	return (1);
}

static int	ft_check_empty_lines(t_data *data, char **str)
{
	int		i;
	int		j;
	char	*temp;

	temp = *str;
	i = ft_strlen(temp);
	j = i;
	if (i == 0)
		return (ft_cleanup_empty_utils(data, str));
	while (ft_strchr("01NSEW \n", temp[j]))
		j--;
	while (j > 0 && j < i && temp[j] != '\n')
		j++;
	while (--i >= j + 2)
	{
		if (temp[i] == '\n' && temp[i - 1] == '\n' && temp[i - 2] == '1')
			return (ft_cleanup_empty_utils(data, str));
	}
	return (0);
}

int	ft_read_cub_file(t_data *data, char *str)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(str, O_RDONLY);
	if (fd == -1 || ft_ends_with(str, ".cub"))
	{
		data->cub = ft_split(" ", ' ');
		data->map = ft_split(" ", ' ');
		return (1);
	}
	line = get_next_line(fd);
	temp = ft_strdup("");
	if (!temp)
		return (1);
	while (line)
	{
		temp = ft_strjoin_ex(temp, line, 3);
		line = get_next_line(fd);
	}
	if (ft_check_empty_lines(data, &temp))
		return (1);
	data->cub = ft_split(temp, '\n');
	free(temp);
	return (0);
}
