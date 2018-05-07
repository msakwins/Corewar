/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:12:47 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/24 16:39:10 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			get_uintlen(uintmax_t nb, char *base)
{
	int					len;
	unsigned int		baselen;

	len = 1;
	baselen = ft_strlen(base);
	while (nb >= baselen)
	{
		nb = nb / baselen;
		len++;
	}
	return (len);
}

int			get_charlen(char c)
{
	write(1, &c, 1);
	return (1);
}

int			get_strlen(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int			get_wstrlen(wchar_t *wstr)
{
	int		size;

	size = 0;
	while (*wstr != '\0')
	{
		size += ft_countbits(*wstr);
		wstr++;
	}
	return (size);
}
