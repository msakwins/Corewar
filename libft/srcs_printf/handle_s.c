/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:40:54 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/24 17:18:00 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			s_flags(t_modif *modi, char *str)
{
	int				ret;
	int				slen;
	int				nblen;

	ret = 0;
	slen = 0;
	nblen = 0;
	slen = ft_strlen(str);
	nblen = PERIOD && PRECI < slen ? PRECI : slen;
	width_errs(modi, nblen);
	if (DIGIT && !MINUS)
		ret += apply_digits(modi);
	if (PERIOD == 1 && PRECI >= 0 && PRECI < slen)
	{
		ret += PRECI;
		ft_putnstr(str, PRECI);
	}
	else
	{
		ft_putstr(str);
		ret += slen;
	}
	if (DIGIT && MINUS)
		ret += apply_digits(modi);
	return (ret);
}

static int			ws_flags(t_modif *modi, wchar_t *wstr)
{
	int				ret;
	int				wlen;
	int				slen;

	ret = 0;
	wlen = 0;
	slen = get_wstrlen(wstr);
	if (PERIOD == 1 && PRECI < slen && PRECI > 0)
		wlen = get_preciw(wstr, PRECI);
	else
		wlen = slen;
	if (PERIOD == 1 && PRECI == 0)
		wlen = 0;
	if (PERIOD == 0 && MINUS)
		ret += ft_putwstr(wstr);
	if (DIGIT > wlen)
	{
		DIGIT = DIGIT - wlen;
		ret += apply_digits(modi);
		if (PERIOD == 0 && !MINUS)
			ret += ft_putwstr(wstr);
	}
	if (PERIOD == 1 && PRECI > 0 && PRECI <= slen)
		ret += ft_putwnstr(wstr, PRECI);
	return (ret);
}

size_t				handle_s(va_list argl, t_modif *modi)
{
	int				ret;
	char			*str;
	wchar_t			*wstr;

	ret = 0;
	wstr = NULL;
	str = NULL;
	if (!CAP && !MOD)
	{
		str = va_arg(argl, char *);
		str = str == NULL ? "(null)" : str;
		if (MOD == 3)
			return (-1);
		ret += (PERIOD || DIGIT) ? s_flags(modi, str) : get_strlen(str);
	}
	if (CAP || MOD)
	{
		wstr = va_arg(argl, wchar_t*);
		if (wstr == NULL)
			return (ret += get_strlen("(null)"));
		ret += (PERIOD || DIGIT) ? ws_flags(modi, wstr) : ft_putwstr(wstr);
	}
	return (ret);
}

size_t				paddingchar(size_t dig, char p)
{
	size_t			len;

	len = 0;
	while (dig)
	{
		len += get_charlen(p);
		dig--;
	}
	return (len);
}
