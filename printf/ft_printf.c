/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:09:01 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:30:40 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print2(char spe, va_list args, int *count)
{
	if (spe == 'c')
		print_char(va_arg(args, int), count);
	else if (spe == 's')
		print_str(va_arg(args, char *), count);
	else if (spe == 'd' || spe == 'i')
		print_int(va_arg(args, int), count);
	else if (spe == 'x' || spe == 'X')
		print_hex(va_arg(args, unsigned int), count, (spe == 'X'));
	else if (spe == '%')
		print_same(count);
	else if (spe == 'p')
		print_pointer(va_arg(args, void *), count);
	else if (spe == 'u')
		print_unsigned(va_arg(args, unsigned int), count);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (-1);
	if (s[i] == '%' && !s[i + 1])
		return (-1);
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX%", s[i + 1]) != NULL)
		{
			print2(s[i + 1], args, &count);
			i = i + 2;
		}
		else
			count += write(1, &s[i++], 1);
	}
	va_end(args);
	return (count);
}
