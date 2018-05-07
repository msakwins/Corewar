/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:39:24 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/24 17:18:31 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	handle_c_minus(t_modif *modi, wchar_t value)
{
	int ret;

	ret = 0;
	ret += apply_preci(modi);
	if (!modi->cap && !modi->mod)
		ret += get_charlen(value);
	else
		ret += ft_putwchar(value);
	return (ret);
}

int			handle_c(va_list argl, t_modif *modi)
{
	int				ret;
	wchar_t			value;
	int				size;

	ret = 0;
	MOD = (MOD == 2) ? 0 : MOD;
	value = ulenght_mod(argl, modi);
	size = ft_countbits(value);
	if (PRECI || PERIOD || FLAG || DIGIT)
	{
		width_errors(modi, size);
		if (MINUS)
			ret += handle_c_minus(modi, value);
		ret += (DIGIT > 0) ? apply_digits(modi) : 0;
	}
	if (!MINUS)
	{
		if (size <= 1 && !CAP && !MOD)
			ret += get_charlen(value);
		else if (!modi->cap && !modi->mod)
			ret += get_charlen(value);
		else
			ret += ft_putwchar(value);
	}
	return (ret);
}
