/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/11 23:47:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		init(t_env *env)
{
	int		i;

	env->visu = 0;
	env->nb_players = 0;
	env->dump = -1;
	env->cycle_to_die = CYCLE_TO_DIE;
	env->winner = 0;
	env->nb_processes = 0;
	env->nb_checks = 0;
	env->head = NULL;
	env->zaz_dump = 0;
	i = 0;
	while (i < MAX_PLAYERS)
	{
		env->player[i].nb = -1;
		env->player[i].header = NULL;
		i++;
	}
	env->verbose = 0;
}
