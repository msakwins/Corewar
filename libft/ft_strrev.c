/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:58:20 by msakwins          #+#    #+#             */
/*   Updated: 2016/11/14 20:59:50 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	swap;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	while (i > j)
	{
		swap = str[j];
		str[j] = str[i];
		str[i] = swap;
		i--;
		j++;
	}
	return (str);
}
