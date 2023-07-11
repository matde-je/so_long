#include "so_long.h"

void	check_map(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 4] == "." && path[i - 3] == "b"
		&& path[i - 2] == "e" && path[i - 1] == "r")
		check_map2(path);
	else
		error("Invalid map");
}

void	check_map2(char *path)
{
	int		fd;
	char	*gnl;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	fd = open(path, O_RDONLY);
	while (fd)
	{
		map()->matrix[count] = get_next_line(fd);
		count++;
	}
	map()->size_y = count;
	check_chars();
}

void	check_chars(void)
{

}
