/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:36:19 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:31:34 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int z, int *count)
{
	char	c;

	if (z >= 10)
		print_unsigned(z / 10, count);
	c = z % 10 + '0';
	write(1, &c, 1);
	(*count)++;
}
