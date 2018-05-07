/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 17:17:21 by msakwins          #+#    #+#             */
/*   Updated: 2017/06/11 18:47:31 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		handle_b(va_list argl, t_modif *modi)
{
	uintmax_t			nb;
	size_t				len;
	size_t				nblen;

	len = 0;
	nb = ulenght_mod(argl, modi);
	nblen = get_uintlen(nb, BASE_2);
	ft_putnbr_base(nb, BASE_2);
	len += nblen;
	return (len);
}
