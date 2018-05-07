/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:21 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/26 15:33:55 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		o_flags(uintmax_t nb, t_modif *modi, int nblen)
{
	int					ret;

	ret = 0;
	if (SHARP)
		DIGIT -= 1;
	if (PRECI || DIGIT)
		width_errors(modi, nblen);
	if (MINUS)
	{
		if (SHARP && !PRECI)
			ret += get_charlen('0');
		ret += apply_preci(modi);
		ft_putnbr_base(nb, BASE_8);
	}
	if (PLUS || SPACE)
		ret += apply_flags(modi);
	if (DIGIT > 0 || (SHARP && DIGIT == 0))
	{
		ret += apply_digits(modi);
		if (!MINUS && SHARP && !PRECI)
			ret += get_charlen('0');
	}
	if (PRECI > 0 && !MINUS)
		ret += apply_preci(modi);
	return (ret);
}

int				handle_o(va_list argl, t_modif *modi)
{
	int					ret;
	uintmax_t			nb;
	int					nblen;

	ret = 0;
	nb = !MOD && !CAP ? va_arg(argl, unsigned) : ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_8);
	PLUS = 0;
	SPACE = 0;
	if (FLAG || PERIOD || PRECI || DIGIT)
	{
		if (SHARP == 1 && nb > 0 && !DIGIT && !PRECI)
			ret += get_charlen('0');
		if (period_zero(nb, modi) && !SHARP)
		{
			ret += apply_digits(modi);
			return (ret);
		}
		ret += o_flags(nb, modi, nblen);
	}
	if (!MINUS)
		ft_putnbr_base(nb, BASE_8);
	ret += nblen;
	return (ret);
}
