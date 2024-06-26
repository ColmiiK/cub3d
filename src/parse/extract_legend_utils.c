/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_legend_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:16:24 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 17:46:26 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_return_split_one(t_data *data)
{
	data->map = ft_split(" ", ' ');
	return (1);
}

int	ft_correct_division(int i, char **cub, t_data *data)
{
	int	j;

	j = 0;
	if (cub[i][0] == '\0' || cub[i][0] == '\n')
		return (0);
	while (cub[i][j] != '\0')
	{
		if (!ft_strchr("10 \n", cub[i][j]))
		{
			if (ft_strchr("NSEW", cub[i][j]) && j != 0
				&& (ft_strchr("10", cub[i][j - 1])
				&& ft_strchr("10", cub[i][j + 1])))
				;
			else
				return (ft_return_split_one(data));
		}
		j++;
	}
	return (0);
}
