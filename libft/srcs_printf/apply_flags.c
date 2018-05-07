/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 19:52:29 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/26 15:41:37 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		width_errors(t_modif *modi, int nblen)
{
	if (PRECI > 0)
		ZERO = 0;
	if ((PLUS && !NEG) || SPACE)
		DIGIT = DIGIT - 1;
	if (DIGIT > 0 || PRECI > 0)
	{
		DIGIT = DIGIT <= nblen ? 0 : DIGIT;
		PRECI = PRECI <= nblen ? 0 : PRECI;
	}
	if (DIGIT > 0 && PRECI == 0)
		DIGIT = DIGIT - nblen;
	else if (PRECI > 0 && DIGIT == 0)
		PRECI = PRECI - nblen;
	else if (DIGIT > nblen && PRECI > nblen)
	{
		DIGIT = DIGIT - PRECI;
		PRECI = PRECI - nblen;
	}
	else if (DIGIT > nblen && PRECI < nblen)
		DIGIT = DIGIT - nblen;
	else if (DIGIT < nblen && PRECI > nblen)
		PRECI = PRECI - nblen;
}

void		width_errs(t_modif *modi, int slen)
{
	if (DIGIT > 0 && DIGIT < slen)
		DIGIT = 0;
	if (DIGIT > 0 && !PERIOD)
		DIGIT = DIGIT - slen;
	if (DIGIT > 0 && PERIOD > 0)
		DIGIT = DIGIT - slen;
}

int			apply_flags(t_modif *modi)
{
	int		ret;

	ret = 0;
	if (PLUS == 1 && SPACE == 1)
		SPACE = 0;
	if (PLUS == 1 && !NEG && PRECI == 0)
		ret += get_charlen('+');
	if (SPACE == 1 && !NEG)
		ret += get_charlen(' ');
	return (ret);
}

int			apply_digits(t_modif *modi)
{
	int		ret;
	char	p;

	ret = 0;
	DIGIT -= NEG == 1 ? 1 : 0;
	if (MINUS == 1 && ZERO == 1)
		ZERO = 0;
	p = ZERO == 1 ? '0' : ' ';
	if (DIGIT > 0)
		ret += padding(DIGIT, p);
	return (ret);
}

int			apply_preci(t_modif *modi)
{
	int		ret;

	ret = 0;
	if (PLUS && !NEG)
		ret += get_charlen('+');
	if (PERIOD)
	{
		ret += padding(PRECI, '0');
	}
	return (ret);
}
