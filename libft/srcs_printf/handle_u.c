/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 15:46:28 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 23:17:49 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		u_flags(uintmax_t nb, t_modif *modi, int nblen)
{
	int					ret;

	ret = 0;
	if (DIGIT || PRECI)
		width_errors(modi, nblen);
	if (MINUS)
	{
		ret += minus_spec(modi, nb);
	}
	if (DIGIT > 0)
	{
		ret += apply_digits(modi);
	}
	if (PRECI > 0 && !MINUS)
		ret += apply_preci(modi);
	return (ret);
}

int				handle_u(va_list argl, t_modif *modi)
{
	int					ret;
	uintmax_t			nb;
	int					nblen;
	int					neg;

	ret = 0;
	neg = 0;
	nb = !MOD && !CAP ? va_arg(argl, unsigned) : ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_10);
	PLUS = 0;
	SPACE = 0;
	if (PERIOD || FLAG || PRECI || DIGIT)
	{
		if (SHARP == 1 && nb > 0)
			ret += get_charlen('0');
		if (period_zero(nb, modi))
			return (ret + apply_digits(modi));
		ret += u_flags(nb, modi, nblen);
	}
	if (!MINUS)
		ft_putnbr_base(nb, BASE_10);
	ret += nblen;
	return (ret);
}
