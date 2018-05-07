/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/11 01:44:19 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		print_zaz_dump(t_env *e)
{
	int		i;
	int		hex;
	int		p;

	hex = 0;
	i = 0;
	p = -1;
	ft_printf("Introducing contestants... (Our Corewar)\n");
	while (++p < e->nb_players)
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			p + 1, e->player[p].header->prog_size,
			e->player[p].header->prog_name, e->player[p].header->comment);
	while (i < MEM_SIZE)
	{
		if ((i) % (64) == 0)
			ft_printf("0x%04x : ", hex);
		ft_printf("%02x ", LBYTE(e->arena[i]));
		if ((i + 1) % (64) == 0)
		{
			ft_printf("\n");
			hex += 64;
		}
		i++;
	}
	exit(1);
}

void			print_dump(t_env *e)
{
	int		i;
	int		hex;

	if (e->visu)
		endwin();
	if (e->zaz_dump)
		print_zaz_dump(e);
	hex = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		if ((i) % (32) == 0)
			ft_printf("0x%04x : ", hex);
		ft_printf("%02x ", LBYTE(e->arena[i]));
		if ((i + 1) % (32) == 0)
		{
			ft_printf("\n");
			hex += 32;
		}
		i++;
	}
	exit(1);
}
