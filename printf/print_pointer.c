/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:54:29 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:31:22 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_pointer_hex(unsigned long long address, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (address >= 16)
		print_pointer_hex(address / 16, count);
	write (1, &base[address % 16], 1);
	(*count)++;
}

void	print_pointer(void *ptr, int *count)
{
	unsigned long long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
		return ;
	}
	address = (unsigned long long)ptr;
	write(1, "0x", 2);
	(*count) += 2;
	print_pointer_hex(address, count);
}
