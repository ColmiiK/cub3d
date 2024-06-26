/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albagar4 <albagar4@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:16:52 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 13:06:16 by albagar4         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	ft_check_for_letters(char **map)
{
	int		i;
	int		j;
	int		count;
	char	*allowed;

	allowed = " 10NSEWLU";
	i = -1;
	count = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(allowed, map[i][j]))
				return (1);
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
		}
	}
	if (count != 1)
		return (1);
	return (0);
}

int	ft_check_map(char **map)
{
	if (ft_check_for_letters(map))
		return (ft_error("Map contains invalid character(s)"));
	if (ft_inject_space(map))
		return (ft_error("Unable to validate map"));
	return (0);
}
