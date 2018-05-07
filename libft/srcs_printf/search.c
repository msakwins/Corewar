/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:05:55 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/22 20:11:14 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			search_percent(const char *format, int i, t_modif *modi)
{
	modi->percent = 0;
	if (format[i] == '\0')
		return (1);
	return (0);
}

void		search_mod(const char *format, int i, t_modif *modi)
{
	MOD = 0;
	if (format[i] == 'h')
	{
		MOD = 1;
		i++;
		if (format[i] == 'h')
			MOD = 2;
	}
	else if (format[i] == 'l')
	{
		MOD = 3;
		i++;
		if (format[i] == 'l')
			MOD = 4;
	}
	else if (format[i] == 'j')
		MOD = 5;
	else if (format[i] == 'z')
		MOD = 6;
}

void		search_flag(const char *format, int i, t_modif *modi)
{
	FLAG = 0;
	while (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
			format[i] == '+' || format[i] == ' ')
	{
		if (format[i] == '#')
			SHARP = 1;
		else if (format[i] == '0')
			ZERO = (MINUS) ? 0 : 1;
		else if (format[i] == '-')
		{
			MINUS = 1;
			ZERO = 0;
		}
		else if (format[i] == '+')
			PLUS = 1;
		else if (format[i] == ' ')
			SPACE = 1;
		i++;
		FLAG++;
	}
}

int			search_digit(va_list argl, const char *format, int i, t_modif *modi)
{
	int		len;
	int		star_handler;

	DIGIT = 0;
	if (!ft_isdigit(format[i]))
	{
		if (format[i] == '*')
		{
			star_handler = (int)va_arg(argl, uintmax_t);
			DIGIT = (star_handler >= 0) ? star_handler : -star_handler;
			MINUS = (star_handler >= 0) ? 0 : 1;
			return (1);
		}
		return (0);
	}
	DIGIT = ft_atoi(format + i);
	len = get_uintlen(DIGIT, BASE_10);
	return (len);
}

int			search_period(va_list argl, const char *format,
				int i, t_modif *modi)
{
	int		len;
	int		star_handler;

	PRECI = 0;
	if (!ft_isdigit(format[i]))
	{
		if (format[i] == '*')
		{
			star_handler = (int)va_arg(argl, uintmax_t);
			PRECI = (star_handler >= 0) ? star_handler : 0;
			PERIOD = (star_handler >= 0) ? 1 : 0;
			return (1);
		}
		return (0);
	}
	PRECI = ft_atoi(format + i);
	len = get_uintlen(PRECI, BASE_10);
	return (len);
}
