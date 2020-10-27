/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpavel <gpavel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:20:58 by gpavel            #+#    #+#             */
/*   Updated: 2020/10/27 11:26:09 by gpavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int ft_upto_line(char **s, char **line, int fd, int n)
{
	char	*aux;
	int		len;

	len = 0;
	while (s[0][len] != '\n' && s[0][len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		aux = ft_strdup(&(*s)[len + 1]);
		free(*s);
		*s = ft_strdup(aux);
		free(aux);
	}
	else if ((*s)[len] == '\0')
	{
		if (n == BUFFER_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(*s);
		*s = NULL;
		if (n == 0)
			return (0);
	}
	return (1);
}
int get_next_line(int fd, char **line)
{
	static char		*str[256];
	char			buffer[BUFFER_SIZE + 1];
	char			*aux;
	int				n;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[n] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(aux);
			free(aux);
		}
		if (ft_strchr(buffer, '\n'))
			break;
	}
	if (n < 0)
		return (-1);
	if ((n == 0) && (str[fd] == NULL || str[fd] == '\0'))
		{
			*line = ft_strdup("");
			return (0);
		}
	return (ft_upto_line(&str[fd], line, fd, n));
}
