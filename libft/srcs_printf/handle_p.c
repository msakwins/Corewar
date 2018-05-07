/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 17:41:39 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 21:59:01 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_flags(t_modif *modi, uintmax_t nb, int nblen)
{
	int ret;

	ret = 0;
	if (PRECI || DIGIT)
		width_errors(modi, nblen);
	if (SHARP == 1 && nb > 0)
		ret += get_charlen('0');
	if (MINUS || ZERO)
	{
		ret += get_strlen("0x");
		ft_putnbr_base(nb, HEXA_MIN);
	}
	if (DIGIT > 0)
	{
		ret += apply_digits(modi);
	}
	if (!MINUS && !ZERO)
		ret += get_strlen("0x");
	if (PRECI > 0)
		ret += apply_preci(modi);
	if (!MINUS && !ZERO)
		ft_putnbr_base(nb, HEXA_MIN);
	ret += get_uintlen(nb, HEXA_MIN);
	return (ret);
}

int			handle_p(va_list argl, t_modif *modi)
{
	int				ret;
	uintmax_t		nb;
	int				nblen;

	ret = 0;
	modi->hexa = 1;
	nb = (uintmax_t)va_arg(argl, void*);
	nblen = get_uintlen(nb, HEXA_MIN);
	DIGIT -= 2;
	PLUS = 0;
	SPACE = 0;
	if (period_zero(nb, modi))
		return (ret + get_strlen("0x"));
	ret += handle_flags(modi, nb, nblen);
	return (ret);
}
