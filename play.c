/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:48:42 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:11:34 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_map *elm, int x, int y)
{
	int (x_new), (y_new);
	x_new = elm->player_x + x;
	y_new = elm->player_y + y;
	if (elm->map[x_new][y_new] == '1')
		return ;
	if (elm->map[x_new][y_new] == 'C')
		elm->collectibles--;
	if (elm->map[x_new][y_new] == 'E')
	{
		if (elm->collectibles == 0)
			return (ft_printf("moves: %d\n", ++(elm->moves)),
				ft_printf("You win!\n"), free_all(elm), exit(0));
		else
			return ;
	}
	elm->map[elm->player_x][elm->player_y] = '0';
	elm->map[x_new][y_new] = 'P';
	elm->player_x = x_new;
	elm->player_y = y_new;
	draw_map(elm);
	ft_printf("moves: %d\n", ++(elm->moves));
}

int	key_listen(int key_code, t_map *elm)
{
	if (key_code == XK_Escape)
	{
		free_all(elm);
		exit(0);
		return (0);
	}
	else if (key_code == XK_w || key_code == XK_Up)
		move(elm, -1, 0);
	else if (key_code == XK_s || key_code == XK_Down)
		move(elm, 1, 0);
	else if (key_code == XK_a || key_code == XK_Left)
		move(elm, 0, -1);
	else if (key_code == XK_d || key_code == XK_Right)
		move(elm, 0, 1);
	return (1);
}

int	close_win(t_map *elm)
{
	free_all(elm);
	exit(0);
	return (0);
}

int	run_the_game(t_map *elm)
{
	elm->mlx = mlx_init();
	if (!elm->mlx)
		return (0);
	elm->win = mlx_new_window(elm->mlx, elm->columns * SIZE, elm->rows * SIZE,
			"so_long");
	if (!elm->win)
		return (free_all(elm), 0);
	if (image_to_ptr(elm) == 0)
		return (free_all(elm), 0);
	draw_map(elm);
	mlx_key_hook(elm->win, &key_listen, elm);
	mlx_hook(elm->win, 17, 0, &close_win, elm);
	mlx_loop(elm->mlx);
	return (1);
}
