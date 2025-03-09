/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:37:28 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/09 17:13:46 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_name(char *str)
{
	int		len;
	char	*ptr;

	if (str == NULL)
		return (0);
	ptr = ft_strrchr(str, '/');
	if (ptr != NULL && ptr[1] == '.')
		return (0);
	len = ft_strlen(str);
	if (len > 4 && str[len - 1] == 'r' && str[len - 2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.')
		return (1);
	return (0);
}
