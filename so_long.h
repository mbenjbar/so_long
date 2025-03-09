/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:11:50 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:13:19 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define SIZE 50

typedef struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	int		player_x;
	int		player_y;
	int		coins;
	int		collectibles;
	int		moves;
	void	*mlx;
	void	*win;
	void	*player;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*exit;
}	t_map;
int		check_name(char *str);
int		check_map(char *file_name, t_map *elm);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
void	free_map(char **map);
int		check_walls(char **map, int rows, int columns);
void	free_all(t_map *elm);
int		image_to_ptr(t_map *elm);
void	draw_map(t_map *elm);
int		run_the_game(t_map *elm);
int		flood_fill(t_map *elm);

#endif