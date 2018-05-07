/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 19:56:57 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 23:13:57 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		d_flags(t_modif *modi, intmax_t nb, int nblen)
{
	int				ret;

	ret = 0;
	if (PRECI > 0 || DIGIT > 0)
		width_errors(modi, nblen);
	if (MINUS)
	{
		if (NEG)
			ret += get_charlen('-');
		ret += apply_preci(modi);
		ft_putnbr_base(nb, BASE_10);
	}
	if (PLUS || SPACE)
		ret += apply_flags(modi);
	return (ret);
}

static int		d_width(t_modif *modi)
{
	int				ret;
	int				negatif;

	ret = 0;
	negatif = 0;
	if ((ZERO == 1) && NEG == 1)
	{
		ret += get_charlen('-');
		negatif = 1;
	}
	if (DIGIT > 0)
		ret += apply_digits(modi);
	if (NEG == 1 && !negatif && PRECI > 0)
	{
		ret += get_charlen('-');
		negatif = 1;
	}
	if (PRECI > 0 && !MINUS)
		ret += apply_preci(modi);
	return (ret);
}

int				handle_d(va_list argl, t_modif *modi)
{
	int				ret;
	intmax_t		nb;
	int				nblen;

	ret = 0;
	nb = !MOD && !CAP ? va_arg(argl, int) : lenght_mod(argl, modi);
	NEG = nb < 0 ? 1 : 0;
	nb = NEG == 1 ? -nb : nb;
	nblen = get_uintlen(nb, BASE_10);
	if (PERIOD || FLAG || PRECI || DIGIT)
	{
		if (period_zero(nb, modi))
		{
			ret += apply_digits(modi);
			return (ret);
		}
		ret += d_flags(modi, nb, nblen);
		ret += d_width(modi);
	}
	if (NEG == 1 && !ZERO && !PRECI && !MINUS)
		ret += get_charlen('-');
	if (!MINUS)
		ft_putnbr_base(nb, BASE_10);
	ret += nblen;
	return (ret);
}
