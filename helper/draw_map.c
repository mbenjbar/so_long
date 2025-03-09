/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:30:42 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:19:11 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map2(t_map *elm, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(elm->mlx, elm->win, elm->wall,
			j * SIZE, i * SIZE);
	if (c == '0')
		mlx_put_image_to_window(elm->mlx, elm->win, elm->floor,
			j * SIZE, i * SIZE);
	if (c == 'C')
		mlx_put_image_to_window(elm->mlx, elm->win, elm->coin,
			j * SIZE, i * SIZE);
	if (c == 'E')
		mlx_put_image_to_window(elm->mlx, elm->win, elm->exit,
			j * SIZE, i * SIZE);
	if (c == 'P')
		mlx_put_image_to_window(elm->mlx, elm->win, elm->player,
			j * SIZE, i * SIZE);
}

void	draw_map(t_map *elm)
{
	int (i), (j);
	i = 0;
	while (i < elm->rows)
	{
		j = 0;
		while (j < elm->columns)
		{
			draw_map2(elm, elm->map[i][j], i, j);
			j++;
		}
		i++;
	}
}
