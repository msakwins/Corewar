/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:50:07 by msakwins          #+#    #+#             */
/*   Updated: 2017/10/09 22:51:19 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strleeks(char **phrase, char **s)
{
	char	*str;

	str = NULL;
	str = ft_strjoin(*phrase, *s);
	ft_strdel(s);
	ft_strdel(phrase);
	return (str);
}

char	*ft_cuprest(int n, char *phrase, int c)
{
	int		i;
	int		j;
	char	*str;
	char	*str2;

	j = -1;
	if (!(str = (char*)malloc(sizeof(char) * c + 1)))
		return (NULL);
	if (!(str2 = malloc(sizeof(char) * (ft_strlen(phrase)))))
		return (NULL);
	while (phrase[++j] != '\n')
		str[j] = phrase[j];
	str[j] = '\0';
	i = j;
	j = -1;
	while (phrase[++i] != '\0')
		str2[++j] = phrase[i];
	str2[++j] = '\0';
	if (n == 0)
	{
		ft_strdel(&str2);
		return (str);
	}
	ft_strdel(&str);
	return (str2);
}

char	*ft_cpybuf(char *buf1, int fd, int *res)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*phrase;
	char	*s;

	s = NULL;
	phrase = ft_strdup(buf1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		s = ft_strnew(ret);
		ft_strncpy(s, buf, ret);
		phrase = ft_strleeks(&phrase, &s);
		if ((ft_strchr(phrase, '\n')))
			break ;
	}
	*res = ret;
	return (phrase);
}

void	ft_rest(char **rest, char **phrase)
{
	char	*t;
	int		i;

	t = NULL;
	i = 0;
	if ((*rest))
	{
		if ((*phrase))
			*phrase = ft_strleeks(rest, phrase);
		else
			*phrase = ft_strdup(*rest);
	}
	t = ft_strdup(*phrase);
	if ((ft_strchr(*phrase, '\n')))
	{
		while (t[i] != '\n')
			i++;
		*rest = ft_cuprest(1, *phrase, i);
		ft_strdel(phrase);
		*phrase = ft_cuprest(0, t, i);
	}
	else
		ft_strdel(rest);
	ft_strdel(&t);
}

int		get_next_line(const int fd, char **line)
{
	int			res;
	char		buf[BUFF_SIZE + 1];
	static char	*rest;
	char		*phrase;

	if (BUFF_SIZE < 0)
		return (-1);
	res = read(fd, buf, BUFF_SIZE);
	if (res == -1 || fd == -1)
		return (-1);
	if (res == 0 && (rest == NULL || !ft_strlen(rest)))
		return (0);
	buf[res] = '\0';
	phrase = ft_cpybuf(buf, fd, &res);
	ft_rest(&rest, &phrase);
	*line = ft_strdup(phrase);
	ft_strdel(&phrase);
	return (1);
}
