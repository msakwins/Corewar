/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:25 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			gonna_free_for_nothing(t_env *e)
{
	int			i;
	t_process	*tmp;
	t_process	*tmp2;

	i = 0;
	while (i < e->nb_players)
	{
		if (e->player[i].header)
			free(e->player[i].header);
		i++;
	}
	i = 0;
	tmp = e->head;
	while (i < e->nb_processes)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2)
			free(tmp2);
		i++;
	}
}

void			ft_exit(t_env *e, int i, char *str)
{
	if (i == 4)
	{
		ft_putstr_fd("Rules: \n", 2);
		ft_putstr_fd("1: usage: ./corewar [-dump nb] [[-n nb] champ1.cor]\n",
			2);
		ft_putstr_fd("2: option '-verbose' for a detailed corewar\n", 2);
		ft_putstr_fd("3: option '-zaz' dump as zaz does\n", 2);
		ft_putstr_fd("4: option '-dump nb' dump the memory on the standard", 2);
		ft_putstr_fd("output after nb cycles and exit the corewar\n", 2);
		ft_putstr_fd("5: option '-visu' to set a visualizer\n", 2);
		ft_putstr_fd("3: option '-n nb' set a number for the next player\n", 2);
		ft_putstr_fd("4: you can add 1 to 4 champions in the arena\n", 2);
		exit(1);
	}
	ft_putstr_fd("Error: ", 2);
	if (i == 1)
		ft_putstr_fd("(Syntax) ", 2);
	if (i == 2)
		ft_putstr_fd("Do you even read the rules? ", 2);
	ft_putendl_fd(str, 2);
	gonna_free_for_nothing(e);
	exit(1);
}
