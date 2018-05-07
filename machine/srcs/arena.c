/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:33 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static t_process	*create_new_process(t_env *env, int i)
{
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	if (!process)
		ft_exit(env, 1, "Malloc for process error");
	process->id_champion = i;
	init_reg(process);
	process->reg[0] = env->player[i].nb;
	process->carry = 0;
	process->opcode = 0;
	process->pc = i * MEM_SIZE / env->nb_players;
	process->wait = 0;
	process->live = 0;
	process->prev = NULL;
	process->next = NULL;
	env->nb_processes++;
	return (process);
}

void				init_arena_and_processes(t_env *env)
{
	int			i;
	t_process	*tmp;

	ft_bzero(env->arena, sizeof(unsigned char) * MEM_SIZE);
	i = env->nb_players - 1;
	while (i >= 0)
	{
		if (i == env->nb_players - 1)
		{
			env->head = create_new_process(env, i);
			env->head->prev = NULL;
			tmp = env->head;
		}
		else
		{
			tmp->next = create_new_process(env, i);
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		ft_memcpy(&(env->arena[i * MEM_SIZE / env->nb_players]),
			env->player[i].code, env->player[i].header->prog_size);
		ft_strdel(&(env->player[i--].code));
	}
	tmp->next = env->head;
	env->head->prev = tmp;
}
