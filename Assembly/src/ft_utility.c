/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:19:02 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:57:44 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

char	*ft_strjoin_my(char *s1, char *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	ft_strdel(&s2);
	return (new);
}

/*
**		ouvre le fichier passe en parametre
** 		quitte le programme avec exit_msg_error si fd == -1
*/

int		ft_open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		exit_msg_error(NULL, "Open failure", -1);
	return (fd);
}

/*
**		renvoi l'adresse du premiers caractere qui n'est pas un espace
**		de la chaine passe en parametre
*/

char	*ft_skip_space(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	return (&s[i]);
}

/*
**		renvoi 1 si la chaine passe en parametre ne commence pas par "#"
**		sinon renvoi 0
*/

int		verif_line(char *line)
{
	char	*tmp;

	tmp = ft_skip_space(line);
	if (tmp[0] == '#' || tmp[0] == '\0')
		return (0);
	return (1);
}

/*
**		renvoi 1 si le caractere est un "espace blanc"
** 		sinon renvoi 0
*/

int		is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	else
		return (0);
}
