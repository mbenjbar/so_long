/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:48:14 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:31:54 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*ptr;

	i = 0;
	while (s1[i] != '\0')
		i++;
	ptr = malloc ((i + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lensrc;
	size_t	lendest;

	lensrc = 0;
	while (src[lensrc] != '\0')
		lensrc++;
	if (dstsize == 0)
		return (lensrc);
	lendest = 0;
	while (dst[lendest] != '\0')
		lendest++;
	i = lendest;
	if (dstsize <= lendest)
		return (dstsize + lensrc);
	j = 0;
	while (i < dstsize - 1 && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lensrc + lendest);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	result_size;

	len_s1 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2] != '\0')
		len_s2++;
	result_size = len_s1 + len_s2 + 1;
	result = malloc(result_size);
	if (result == NULL)
	{
		free (s1);
		return (NULL);
	}
	ft_strlcpy(result, s1, result_size);
	ft_strlcat(result, s2, result_size);
	free(s1);
	return (result);
}
