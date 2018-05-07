/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:43:15 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/13 00:34:22 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	increment_pc(t_env *env, t_process *current, int size)
{
	current->pc = M((current->pc + size));
	if (current->pc >= MEM_SIZE)
		current->pc -= MEM_SIZE;
	get_opcode(env, current);
}

static void	exec_instruction(t_env *env, t_process *current)
{
	int		size;
	t_ocp	ocp;

	ocp = get_ocp(env, current);
	size = g_op[current->opcode].func(env, current, ocp);
	increment_pc(env, current, size);
}

static void	exec_cycle(t_env *env)
{
	t_process	*tmp;
	int			i;

	tmp = env->head;
	i = 0;
	while (i < env->nb_processes)
	{
		if (tmp->opcode)
		{
			if (tmp->wait == 0)
				exec_instruction(env, tmp);
			else
				tmp->wait--;
		}
		else
			increment_pc(env, tmp, 1);
		tmp = tmp->next;
		i++;
	}
}

void		init_lifecycle(t_env *env)
{
	env->cycle_to_die = CYCLE_TO_DIE;
	env->cycle = 1;
	env->nb_lives = 0;
	env->nb_checks = 0;
}

void		launch_lifecycle(t_env *env)
{
	int		check;
	int		cycle_to_die;

	check = 1;
	init_lifecycle(env);
	load_all_opcode(env);
	cycle_to_die = env->cycle_to_die;
	while (check)
	{
		if (env->visu)
			visu(env, cycle_to_die);
		exec_cycle(env);
		if (env->cycle == env->dump)
			print_dump(env);
		check = check_cycles(env, &cycle_to_die);
		cycle_to_die--;
		if (cycle_to_die == 0)
		{
			check = 1;
		}
		env->cycle++;
	}
}
