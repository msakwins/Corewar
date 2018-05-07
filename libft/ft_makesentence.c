/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makesentence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:01:51 by msakwins          #+#    #+#             */
/*   Updated: 2016/11/14 21:23:04 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_makesentence(const char *str)
{
	char	*new;
	int		dot;

	if (!str)
		return (NULL);
	dot = 1;
	if (str[ft_strlen(str) - 1] == '.' || str[ft_strlen(str) - 1] == '!'
			|| str[ft_strlen(str) - 1] == '?')
		dot = 0;
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(str) + dot + 1))))
		return (NULL);
	new = ft_strcpy(new, str);
	new[0] = ft_toupper(new[0]);
	if (dot == 0)
		new[ft_strlen(str)] = '\0';
	else
	{
		new[ft_strlen(str)] = '.';
		new[ft_strlen(str) + 1] = '\0';
	}
	return (new);
}
