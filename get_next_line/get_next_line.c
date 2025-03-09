/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjbar <mbenjbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:15:11 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/03/08 17:32:02 by mbenjbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif 

char	*ft_last(char *ptr)
{
	int		i;
	size_t	size;
	char	*result;

	i = 0;
	size = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
	{
		result = ft_strdup(ptr);
		if (result == NULL)
			return (NULL);
		return (result);
	}
	size = i + 2;
	result = malloc(size * sizeof(char));
	if (result == NULL)
		return (lines(ptr, result));
	ft_strlcpy(result, ptr, size);
	return (result);
}

char	*ft_next(char *ptr, int	*a)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	while (ptr[len] != '\0')
		len++;
	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\0')
		return (lines(ptr, NULL));
	result = malloc((len - i + 1) * sizeof(char));
	if (result == NULL)
	{
		*a = 1;
		return (lines(ptr, result));
	}
	ft_strlcpy(result, ptr + i + 1, len - i + 1);
	free (ptr);
	return (result);
}

char	*lines(char *ptr, char *buffer)
{
	if (buffer != NULL)
		free (buffer);
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	return (NULL);
}

char	*ft_read(char *ptr, int fd)
{
	int		bytes_read;
	char	*buffer;
	long	buf;

	buf = (long)BUFFER_SIZE + 1;
	buffer = malloc(buf);
	if (buffer == NULL)
		return (lines(ptr, buffer));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		ptr = ft_strjoin(ptr, buffer);
		if (ptr == NULL)
			return (lines(ptr, buffer));
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1 || (bytes_read == 0 && *ptr == '\0'))
		return (lines(ptr, buffer));
	free (buffer);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char		*tmp;
	int			a;

	if (fd == -2)
		return (lines(ptr, NULL));
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (ptr == NULL)
		ptr = ft_strdup("");
	if (ptr == NULL)
		return (NULL);
	ptr = ft_read(ptr, fd);
	if (ptr == NULL)
		return (NULL);
	tmp = ft_last(ptr);
	if (tmp == NULL)
		return (lines(ptr, tmp));
	a = 0;
	ptr = ft_next(ptr, &a);
	if (a == 1)
		return (lines(ptr, tmp));
	return (tmp);
}
