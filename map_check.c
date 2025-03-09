/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:11:22 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:14:41 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_pec(int fd, t_map *elm)
{
	char	*line;

	int (i), (P), (E);
	P = 0;
	E = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (line[++i] != '\0')
		{
			if (line[i] == 'P')
				P++;
			if (line[i] == 'E')
				E++;
			if (line[i] == 'C')
				elm->coins++;
		}
		elm->rows++;
		free(line);
		line = get_next_line(fd);
	}
	if (P == 1 && E == 1 && elm->coins != 0)
		return (get_next_line(-2), close(fd), 1);
	return (get_next_line(-2), close (fd), 0);
}

char	**get_map(int fd, t_map *elm, char *file_name)
{
	int		i;
	char	**map;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc((elm->rows + 1) * sizeof(char *));
	if (map == NULL)
		return (close(fd), NULL);
	while (i < elm->rows)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	get_next_line(-2);
	close (fd);
	map[i] = NULL;
	return (map);
}

int	check_size(t_map *elm)
{
	int		i;
	size_t	col;

	i = 1;
	col = ft_strlen(elm->map[0]) - 1;
	while (i < elm->rows - 1)
	{
		if (col != ft_strlen(elm->map[i]) - 1)
			return (0);
		i++;
	}
	if (col != ft_strlen(elm->map[elm->rows - 1]))
		return (0);
	elm->columns = col;
	return (1);
}

int	check_valid_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char *file_name, t_map *elm)
{
	int	fd;

	*elm = (t_map){0};
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	if (check_pec(fd, elm) == 0)
		return (0);
	elm->map = get_map(fd, elm, file_name);
	if (elm->map == NULL)
		return (0);
	if (check_size(elm) == 0)
		return (free_map(elm->map), 0);
	if ((check_valid_char(elm->map)) == 0)
		return (free_map(elm->map), 0);
	if (check_walls(elm->map, elm->rows, elm->columns) == 0)
		return (free_map(elm->map), 0);
	if (flood_fill(elm) == 0)
		return (free_map(elm->map), 0);
	if (elm->columns > 77 || elm->rows > 42)
		return (free_map(elm->map), 0);
	return (1);
}
