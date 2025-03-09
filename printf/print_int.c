/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:55:24 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:31:16 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	negat(int n, int *count)
{
	int		i;
	char	s[10];

	i = 0;
	while (n != 0)
	{
		s[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	i--;
	while (i >= 0)
	{
		write (1, &s[i], 1);
		(*count)++;
		i--;
	}
}

void	print_int(int n, int *count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*count) = (*count) + 11;
		return ;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		(*count)++;
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		(*count)++;
	}
	negat(n, count);
}
