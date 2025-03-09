/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:08:56 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:15:31 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *s, int c);
void	print_char(int c, int *count);
void	print_str(char *s, int *count);
void	print_same(int *count);
void	print_hex(unsigned int z, int *count, int up_or_low);
void	print_int(int n, int *count);
void	print_pointer(void *ptr, int *count);
void	print_unsigned(unsigned int z, int *count);

#endif