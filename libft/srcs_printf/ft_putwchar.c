/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 19:33:42 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/23 22:50:02 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_putwchar(wchar_t value)
{
	if (value <= 0x7F)
		ft_putchar(value);
	else if (value <= 0x7FF)
	{
		ft_putchar((value >> 6) + 0xC0);
		ft_putchar((value & 0x3F) + 0x80);
		return (2);
	}
	else if (value <= 0xFFFF)
	{
		ft_putchar((value >> 12) + 0xE0);
		ft_putchar(((value >> 6) & 0x3F) + 0x80);
		ft_putchar((value & 0x3F) + 0x80);
		return (3);
	}
	else if (value <= 0x10FFFF)
	{
		ft_putchar((value >> 18) + 0xF0);
		ft_putchar(((value >> 12) & 0x3F) + 0x80);
		ft_putchar(((value >> 6) & 0x3F) + 0x80);
		ft_putchar((value & 0x3F) + 0x80);
		return (4);
	}
	return (1);
}
