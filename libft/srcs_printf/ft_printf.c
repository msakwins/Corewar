/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:47:12 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/24 17:05:14 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		handle(char c, va_list argl, t_modif *modi)
{
	if (c == 'D' || c == 'O' || c == 'X' || c == 'U' || c == 'C' || c == 'S')
		CAP = 1;
	if (c == 'd' || c == 'i' || c == 'D')
		return (handle_d(argl, modi));
	else if (c == 'o' || c == 'O')
		return (handle_o(argl, modi));
	else if (c == 'x' || c == 'X')
		return (handle_x(argl, modi));
	else if (c == 'u' || c == 'U')
		return (handle_u(argl, modi));
	else if (c == 'p')
		return (handle_p(argl, modi));
	else if (c == 'c' || c == 'C')
		return (handle_c(argl, modi));
	else if (c == 's' || c == 'S')
		return (handle_s(argl, modi));
	else if (c == 'b')
		return (handle_b(argl, modi));
	return (0);
}

static int		parse_flags(va_list argl, const char *format,
					int i, t_modif *modi)
{
	search_flag(format, i, modi);
	i += (modi->flag > 0) ? modi->flag : 0;
	i += search_digit(argl, format, i, modi);
	if (format[i] == '*' || ft_isdigit(format[i]))
		i += search_digit(argl, format, i, modi);
	if (format[i] == '.')
	{
		i++;
		PERIOD = 1;
		i += search_period(argl, format, i, modi);
	}
	search_mod(format, i, modi);
	i += (modi->mod > 0) ? 1 : 0;
	if (modi->mod == 2 || modi->mod == 4)
		i++;
	if (format[i] == '\0')
	{
		modi->percent = search_percent(format, i, modi);
		if (modi->percent)
			return (0);
	}
	return (i);
}

static int		parse_percent(va_list argl, const char *format,
	t_modif *modi, int *i)
{
	int		ret;

	ret = 0;
	if (format[*i] == '\0')
		return (-1);
	if (ft_strchr("sSpdDioOuUxXcCb?", format[*i]))
		ret += handle(format[*i], argl, modi);
	else
	{
		*i = parse_flags(argl, format, *i, modi);
		if (modi->percent == 1)
			return (-1);
		if (ft_strchr("sSpdDioOuUxXcCb?", format[*i]))
			ret += handle(format[*i], argl, modi);
		else
			ret += handle_bd(modi, format[*i]);
	}
	return (ret);
}

int				parse(va_list argl, const char *format)
{
	int					i;
	int					ret;
	t_modif				modi;
	int					tmp_ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		init_all(&modi);
		if (format[i] == '%')
		{
			i++;
			tmp_ret = parse_percent(argl, format, &modi, &i);
			if (tmp_ret == -1)
				return (0);
			ret += tmp_ret;
		}
		else
			ret += get_charlen(format[i]);
		i++;
	}
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list				argl;
	int					ret;

	ret = 0;
	va_start(argl, format);
	ret = parse(argl, format);
	va_end(argl);
	return (ret);
}
