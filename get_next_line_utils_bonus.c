/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpavel <gpavel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 10:20:20 by gpavel            #+#    #+#             */
/*   Updated: 2020/10/27 11:26:42 by gpavel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "get_next_line_bonus.h"

int		ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (str[n] != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	x = 1 + ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(x)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[i] != '\0')
	{
		str[j + i] = s2[i];
		i++;
	}
	str[j + i] = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, int c)
{
	char	*p;
	int		s;

	p = (char *)str;
	s = ft_strlen(p) + 1;
	if ((c == '\0') && (*p == '\0'))
		return ((char *)p);
	while (s-- > 0)
	{
		if (*p == c)
			return (p);
		p++;
	}
	return (0);
}


char	*ft_substr(char const *s, unsigned int start, int len)
{
	char			*subs;
	int	i;

	if ((unsigned int)ft_strlen((char *)s) < start)
		return (ft_strdup(""));
	if (!(subs = (char *)malloc(len + 1)) || !s)
		return (NULL);
	i = 0;
	while (i < len)
		subs[i++] = ((char *)s)[start++];
	subs[i] = '\0';
	return (subs);
}
