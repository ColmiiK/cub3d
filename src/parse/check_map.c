#include <cub3d.h>

static int	ft_check_for_letters(char **map)
{
	int		i;
	int		j;
	char	*allowed;

	allowed = " 10NSEW";
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(allowed, map[i][j]))
				return (1);
		}
	}
	return (0);
}

static int ft_check_longest_line(char **map)
{
	int biggest;
	int new;

	while (*map)
	{
		new = ft_strlen(*map);
		if (new > biggest)
			biggest = new;
		map++;
	}
	return (biggest);
}

static char **ft_create_map(int size, int longest)
{
	char **temp;
	int i;

	temp = (char **)malloc(sizeof(char *) * size + 1);
	if (!temp)
		return (NULL);
	i = -1;
	while (temp[++i])
	{
		temp[i] = malloc(sizeof(char) * (longest + 1));
		// temp[i] = ft_calloc(sizeof(char), longest + 1);
		if (!temp[i])
			return (NULL);
	}
	temp[++i] = NULL;
	return (temp);
}

static char **ft_populate_new_map(char **new, char **old, int longest, int size)
{
	int i;
	int j;

	ft_memset(new[0], ' ', longest);
	i = 0;
	while (++i < size)
	{
		write(1, "ey\n", 3);
		printf("-> %s\n", new[i]);
		printf("-> %s\n", old[i - 1]);
		new[i][0] = ' ';
		ft_strlcpy(new[i], old[i - 1], ft_strlen(old[i - i]));
		j = ft_strlen(new[i]);
		while (new[i][j] != '\0')
			new[i][j++] = ' ';

	}
	new[i - 1] = ft_strdup("");
	ft_memset(new[i - 1], ' ', longest);
	new[++i] = NULL;
	for(int i = 0; new[i]; i++)
		printf("-> %s\n", new[i]);
	return (new);
}

int ft_inject_space(char **map)
{
	int size;
	int longest;
	char **new_map;

	size = ft_double_ptr_amount(map) + 2;
	longest = ft_check_longest_line(map) + 2;
	new_map = ft_create_map(size, longest);
	new_map = ft_populate_new_map(new_map, map, longest, size);
	if (!new_map)
		return (1);


	return (0);
}

int ft_check_map(char **map)
{
	if (ft_check_for_letters(map))
		return (ft_error("map contains invalid character(s)"));
	if (ft_inject_space(map))
		return (ft_error("unable to validate map"));
	return (0);
}
