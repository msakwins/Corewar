/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:45:10 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 22:50:25 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_countbits(wchar_t value)
{
	if (value <= 0x7F)
		return (1);
	else if (value <= 0x7FF)
		return (2);
	else if (value <= 0xFFFF)
		return (3);
	else if (value <= 0x10FFFF)
		return (4);
	return (0);
}
