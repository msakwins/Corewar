/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:49:26 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:58:15 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		main(int ac, char **av)
{
	int		i;
	t_asm	*param;

	i = 1;
	if (ac == 2)
	{
		if (!ft_check_ext(av[1]))
			return (0);
		param = init_t_asm(av[1]);
		if (ft_parser(param))
			finalize_asm(param);
		clean_env(param);
	}
	else
	{
		ft_print_usage();
		return (0);
	}
	return (1);
}
