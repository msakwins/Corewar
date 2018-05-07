/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:54:02 by msakwins          #+#    #+#             */
/*   Updated: 2016/11/13 21:29:49 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!s)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	new = ft_strncpy(new, s + start, len);
	new[len] = '\0';
	return (new);
}
