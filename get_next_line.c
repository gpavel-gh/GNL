/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpavel <gpavel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:20:58 by gpavel            #+#    #+#             */
/*   Updated: 2020/10/29 14:27:15 by gpavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_fillstr(char *buffer, char *str, int n)
{
	char	*aux;	

	buffer[n] = '\0';
	if (!str)
		str = ft_strdup(buffer);
	else
	{
		aux = ft_strjoin(str, buffer);
		free(str);
		str = ft_strdup(aux);
		free(aux);
	}
	return (str);
}

static int	ft_upto_line(char **s, char **line, int n)
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
		*line = ft_strdup(*s);
		free (*s);
		*s = NULL;
		if (n == 0)
			return (0);
	}
	return (1);
}
int			get_next_line(int fd, char **line)
{
	static char		*str[256];
	char*			buffer;
	int				n;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		str[fd] = ft_fillstr(buffer, str[fd], n);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free (buffer);
	if (n < 0)
		return (-1);
	if ((n == 0) && (str[fd] == NULL || str[fd] == '\0'))
		{
			*line = ft_strdup("");
			return (0);
		}
	return (ft_upto_line(&str[fd], line, n));
}
