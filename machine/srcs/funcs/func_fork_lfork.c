/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_fork_lfork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 23:06:18 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/14 20:36:50 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void			clone_reg(t_process *a, t_process *b)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		b->reg[i] = a->reg[i];
		i++;
	}
}

static t_process	*clone_process(t_env *e, t_process *current)
{
	t_process *process;

	if (!(process = (t_process *)malloc(sizeof(t_process))))
		ft_exit(e, 1, "Malloc for process error");
	clone_reg(current, process);
	process->idx_buffer = 0;
	process->id_champion = current->id_champion;
	process->live = current->live;
	process->carry = current->carry;
	return (process);
}

static int			both_forks(t_env *env, t_process *current, int restr)
{
	short int	value;
	t_process	*forked;
	t_process	*tmp;
	int			i;

	value = (short int)get_data_dir(env, M((current->pc + 1)), 2);
	forked = clone_process(env, current);
	if (restr)
		forked->pc = M((current->pc + value % IDX_MOD));
	else
		forked->pc = M((current->pc + value));
	get_opcode(env, forked);
	if (env->verbose)
		ft_printf("[%5d] (l)fork called from %d : forking to %hd\n",
			env->cycle, current->id_champion, M((current->pc + value)));
	tmp = env->head;
	i = 1;
	while (i++ < env->nb_processes)
		tmp = tmp->next;
	env->head->prev = forked;
	forked->next = env->head;
	env->head = forked;
	tmp->next = env->nb_processes++ ? env->head : env->head;
	env->head->prev = tmp;
	return (3);
}

int					func_lfork(t_env *env, t_process *current)
{
	return (both_forks(env, current, 0));
}

int					func_fork(t_env *env, t_process *current)
{
	return (both_forks(env, current, 1));
}
