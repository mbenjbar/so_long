/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:28:50 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 19:30:17 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	m;
	size_t			i;
	char			*last;

	m = (unsigned char)c;
	last = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == m)
			last = (char *)(s + i);
		i++;
	}
	if (m == s[i])
		return ((char *)(s + i));
	return ((char *)(last));
}
