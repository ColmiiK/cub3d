#include <cub3d.h>

int	ft_check_longest_line(char **map)
{
	int	biggest;
	int	new;

	biggest = 0;
	while (*map)
	{
		new = ft_strlen(*map);
		if (new > biggest)
			biggest = new;
		map++;
	}
	return (biggest);
}

static char	**ft_create_map(int size, int longest)
{
	char **temp;
	int i;

	temp = ft_calloc(sizeof(char *), size + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		temp[i] = ft_calloc(sizeof(char), longest + 1);
		if (!temp[i])
			return (NULL);
	}
	temp[i] = NULL;
	return (temp);
}

static char **ft_populate_new_map(char **new, char **old, int longest, int size)
{
	int i;
	int j;
	ft_memset(new[0], ' ', longest);
	i = 0;
	while(++i < size - 1)
	{
		new[i][0] = ' ';
		ft_strlcpy(new[i] + 1, old[i - 1], longest);
		j = longest;
		while (new[i][--j] == '\0')
			new[i][j] = ' ';
	}
	ft_memset(new[i], ' ', longest);
	return (new);
}

static int ft_check_neighbours(char **map, int i, int j)
{
	if (map[i - 1][j] == ' ')
		return (1);
	if (map[i + 1][j] == ' ')
		return (1);
	if (map[i][j - 1] == ' ')
		return (1);
	if (map[i][j + 1] == ' ')
		return (1);
	return (0);
}

static int ft_is_map_closed(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (ft_check_neighbours(map, i, j))
					return (1);
			}
		}
	}
	return (0);
}

int ft_inject_space(char **map)
{
	int size;
	int longest;
	char **new_map;

	size = ft_double_ptr_amount(map) + 2;
	longest = ft_check_longest_line(map) + 2;
	new_map = ft_create_map(size, longest);
	if (!new_map)
		return (1);
	new_map = ft_populate_new_map(new_map, map, longest, size);
	if (ft_is_map_closed(new_map))
		return (ft_clean_double_ptr(new_map), 1);
	ft_clean_double_ptr(new_map);
	return (0);
}
