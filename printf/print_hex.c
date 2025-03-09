/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:57:55 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:31:13 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int z, int *count, int up_or_low)
{
	char	*base;

	if (up_or_low == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (z >= 16)
		print_hex(z / 16, count, up_or_low);
	write(1, &base[z % 16], 1);
	(*count)++;
}
