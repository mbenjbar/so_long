/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:02:52 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:30:58 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	m;
	size_t			i;

	m = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == m)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == m)
		return ((char *)(s + i));
	else
		return (0);
}
