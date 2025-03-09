/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:16:05 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:16:58 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_reachable(char **map2, int rows, int col)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		j = 0;
		while (j < col)
		{
			if (map2[i][j] == 'P' || map2[i][j] == 'C' || map2[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	to_fill(t_map *elm, char **map2, int x, int y)
{
	if (x < 0 || x >= elm->rows || y < 0 || y >= elm->columns)
		return ;
	if (map2[x][y] != 'C' && map2[x][y] != 'P' && map2[x][y] != '0'
		&& map2[x][y] != 'E')
		return ;
	if (map2[x][y] == 'C')
		elm->collectibles++;
	if ((elm->map[x][y] == 'E') && (elm->collectibles != elm->coins))
	{
		map2[x][y] = 'V';
		return ;
	}
	map2[x][y] = 'V';
	to_fill(elm, map2, x, y + 1);
	to_fill(elm, map2, x, y - 1);
	to_fill(elm, map2, x + 1, y);
	to_fill(elm, map2, x - 1, y);
}

int	flood_fill(t_map *elm)
{
	char	**map2;

	int (i), (j);
	i = -1;
	map2 = malloc((elm->rows + 1) * sizeof(char *));
	while (++i < elm->rows)
	{
		j = -1;
		map2[i] = malloc(sizeof(char) * (elm->columns + 1));
		while (++j < elm->columns)
		{
			map2[i][j] = elm->map[i][j];
			if (map2[i][j] == 'P')
			{
				elm->player_y = j;
				elm->player_x = i;
			}
		}
		map2[i][j] = '\0';
	}
	map2[i] = NULL;
	to_fill(elm, map2, elm->player_x, elm->player_y);
	if (check_reachable(map2, elm->rows, elm->columns) == 0)
		return (free_map(map2), 0);
	return (free_map(map2), 1);
}
