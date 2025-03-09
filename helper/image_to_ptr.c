/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 00:10:08 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:17:31 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	image_to_ptr(t_map *elm)
{
	int (w), (h);
	elm->floor = mlx_xpm_file_to_image(elm->mlx, "textures/floor.xpm", &w, &h);
	elm->player = mlx_xpm_file_to_image(elm->mlx,
			"textures/player.xpm", &w, &h);
	elm->exit = mlx_xpm_file_to_image(elm->mlx, "textures/exit.xpm", &w, &h);
	elm->wall = mlx_xpm_file_to_image(elm->mlx, "textures/wall.xpm", &w, &h);
	elm->coin = mlx_xpm_file_to_image(elm->mlx, "textures/coin.xpm", &w, &h);
	if (!elm->coin || !elm->floor || !elm->wall || !elm->player || !elm->exit)
		return (ft_printf("Error\nwe couldn't find your image!\n"), exit(0), 0);
	return (1);
}
