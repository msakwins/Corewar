/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:42:11 by msakwins          #+#    #+#             */
/*   Updated: 2016/11/13 18:12:35 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*zone;

	if (!(zone = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(zone, size + 1);
	return (zone);
}
