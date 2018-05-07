/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 19:47:02 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/24 16:31:51 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

intmax_t		lenght_mod(va_list argl, t_modif *modi)
{
	intmax_t		nb;

	nb = va_arg(argl, intmax_t);
	if (MOD == 1 && !CAP)
		nb = (short int)nb;
	else if (MOD == 2 && !CAP)
		nb = (char)nb;
	else if ((MOD == 3 && !CAP) || (!MOD && CAP == 1))
		nb = (long int)nb;
	else if ((MOD == 4 && !CAP) || (MOD == 3 && CAP == 1))
		nb = (long long int)nb;
	else if (MOD == 5 || (MOD == 4 && CAP == 1))
		nb = (intmax_t)nb;
	else if (MOD == 6)
		nb = (long int)nb;
	else
		nb = (int)nb;
	return (nb);
}

uintmax_t		ulenght_mod(va_list argl, t_modif *modi)
{
	uintmax_t	nb;

	nb = va_arg(argl, uintmax_t);
	if (modi->mod == 1 && modi->cap != 1)
		nb = (unsigned short int)nb;
	else if (modi->mod == 2 && modi->cap != 1)
		nb = (unsigned char)nb;
	else if (modi->mod == 3 || modi->cap == 1)
		nb = (unsigned long int)nb;
	else if (modi->mod == 4)
		nb = (unsigned long long int)nb;
	else if (modi->mod == 5)
		nb = (uintmax_t)nb;
	else if (modi->mod == 6)
		nb = (size_t)nb;
	else
	{
		nb = (unsigned int)nb;
	}
	return (nb);
}
