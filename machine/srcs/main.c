/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 16:07:14 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:37 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		anounce_the_winner(t_env *env)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
		env->player[env->winner].nb,
		env->player[env->winner].header->prog_name);
}

int				main(int argc, char **argv)
{
	t_env	env;

	init(&env);
	parse_args(&env, argc, argv);
	parse_files(&env, argv);
	init_arena_and_processes(&env);
	if (env.visu)
		init_curse_color();
	launch_lifecycle(&env);
	if (env.visu)
		end_curses(&env);
	anounce_the_winner(&env);
	gonna_free_for_nothing(&env);
	return (0);
}
