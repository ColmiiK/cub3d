/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:20:04 by alvega-g          #+#    #+#             */
/*   Updated: 2024/06/26 16:01:51 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d_bonus.h>

static int	ft_setup_struct(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_tex));
	data->m_x = 0;
	data->m_y = 0;
	data->frame = 0;
	data->shooting_gun = false;
	data->debug_flag = false;
	data->debug_info = NULL;
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
	ft_initialize_mlx(&data);
	ft_cleanup(data);
	return (0);
}
