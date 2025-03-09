/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:24:39 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 15:09:22 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int ac, char **av)
{
	t_map	elm;

	if (ac != 2 || check_name(av[1]) == 0)
		return (ft_printf("Error\nInvalid file path !\n"), 1);
	if (check_map(av[1], &elm) == 0)
		return (ft_printf("Error\nInvalid map !\n"), 1);
	if (run_the_game(&elm))
		return (ft_printf("Error\nWindow failed to run !\n"), 1);
}
