/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:50:44 by msakwins          #+#    #+#             */
/*   Updated: 2017/09/05 16:34:36 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_mod_nl(char *s1, char *s2)
{
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strjoin(s2, "\n"));
	if (!s2)
		return (ft_strdup(s1));
	if (!(new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	new = ft_strcat(new, s1);
	new = ft_strcat(new, s2);
	new = ft_strcat(new, "\n");
	free(s1);
	return (new);
}
