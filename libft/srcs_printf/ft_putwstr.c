/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 21:12:02 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 22:49:49 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_putwstr(wchar_t *wstr)
{
	static int	len;
	int			size;

	len = 0;
	while (*wstr != '\0')
	{
		size = ft_putwchar(*wstr);
		len += size;
		wstr++;
	}
	return (len);
}

int			get_preciw(wchar_t *wstr, int n)
{
	int			size;
	int			clen;
	int			wlen;

	size = 0;
	clen = 0;
	wlen = 0;
	while (n >= clen)
	{
		size = ft_countbits(*wstr);
		clen = size;
		n -= clen;
		wlen += clen;
		wstr++;
	}
	return (wlen);
}

int			ft_putwnstr(wchar_t *wstr, int n)
{
	int			size;
	int			clen;
	int			wlen;

	size = 0;
	clen = 0;
	wlen = 0;
	while (n >= clen)
	{
		size = ft_putwchar(*wstr);
		clen = size;
		n -= clen;
		wlen += clen;
		wstr++;
	}
	return (wlen);
}
