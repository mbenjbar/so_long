/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:30:30 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:16:23 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free (map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_map *elm)
{
	if (elm->floor)
		mlx_destroy_image(elm->mlx, elm->floor);
	if (elm->player)
		mlx_destroy_image(elm->mlx, elm->player);
	if (elm->coin)
		mlx_destroy_image(elm->mlx, elm->coin);
	if (elm->wall)
		mlx_destroy_image(elm->mlx, elm->wall);
	if (elm->exit)
		mlx_destroy_image(elm->mlx, elm->exit);
	if (elm->win)
		mlx_destroy_window(elm->mlx, elm->win);
	if (elm->mlx)
	{
		mlx_destroy_display(elm->mlx);
		free(elm->mlx);
	}
	free_map(elm->map);
}
