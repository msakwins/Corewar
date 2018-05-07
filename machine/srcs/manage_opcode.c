/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_opcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 19:32:29 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/10 22:24:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		get_opcode(t_env *env, t_process *current)
{
	if (env->arena[M((current->pc))] >= 1 && env->arena[M((current->pc))] <= 16)
	{
		current->opcode = env->arena[M((current->pc))];
		current->wait = g_op[env->arena[M((current->pc))]].cycles;
	}
	else
	{
		current->opcode = 0;
		current->wait = 0;
	}
}

void		load_all_opcode(t_env *env)
{
	t_process		*tmp;
	int				i;

	tmp = env->head;
	i = 0;
	while (i < env->nb_processes)
	{
		if (tmp->opcode == 0)
			get_opcode(env, tmp);
		tmp = tmp->next;
		i++;
	}
}
