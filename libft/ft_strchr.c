/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:57:31 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/26 13:40:12 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ss;

	i = 0;
	ss = (char *)s;
	while (ss[i])
	{
		if ((char)c == ss[i])
			return (ss + i);
		i++;
	}
	if ((char)c == ss[i])
		return (ss + i);
	return (NULL);
}
