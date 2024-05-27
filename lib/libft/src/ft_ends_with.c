/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvega-g <alvega-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:18:31 by alvega-g          #+#    #+#             */
/*   Updated: 2024/05/27 11:21:00 by alvega-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_ends_with(char *str, char *to_find)
{
	int	len_str;
	int	len_to_find;

	if (!str || !to_find)
		return (0);
	len_str = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	if (len_to_find > len_str)
		return (0);
	return (ft_strncmp(str + len_str - len_to_find, to_find, len_to_find));
}
