/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:20:54 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:40 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_curses(t_env *env, unsigned k, int y, int x)
{
	int				i;
	t_process		*tmp;

	i = 0;
	tmp = env->head;
	if (env->arena[k])
		attron(COLOR_PAIR(5));
	while (i < env->nb_processes)
	{
		if (tmp->pc == k)
			attron(COLOR_PAIR(tmp->id_champion + 1));
		tmp = tmp->next;
		i++;
	}
	mvprintw(y, x, "%02x", LBYTE(env->arena[k]));
	x = x + 2;
	attron(COLOR_PAIR(7));
	mvprintw(y, x, " ");
	x++;
	if ((k + 1) % (64) == 0)
	{
		y++;
		x = 5;
	}
}

void	init_curses(t_env *env)
{
	unsigned int	k;
	int				y;
	int				x;

	k = 0;
	x = 5;
	y = 1;
	while (k < MEM_SIZE)
	{
		attron(COLOR_PAIR(7));
		print_curses(env, k, y, x);
		x = x + 3;
		if ((k + 1) % (64) == 0)
		{
			y++;
			x = 5;
		}
		k++;
	}
}

void	curses_players(t_env *env)
{
	int			i;
	int			x;
	int			y;
	int			color;

	y = 1;
	x = 205;
	i = 0;
	color = 1;
	while (i < env->nb_players)
	{
		attron(COLOR_PAIR(color));
		mvprintw(y, x, "Player %d : %s",
			env->player[i].nb, env->player[i].header->prog_name);
		mvprintw(y + 1, x + 3, "Lives : %d", env->player[i].live);
		y += 3;
		i++;
		color++;
	}
}

int		visu(t_env *env, int cycles_left)
{
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	if ((getch()) == 32)
	{
		sleep(5);
	}
	erase();
	curses_players(env);
	init_curses(env);
	attron(COLOR_PAIR(6));
	mvprintw(LINES - 5, 5, " Lives: %d ", env->nb_lives);
	mvprintw(LINES - 3, 5, " Cycles: %d / %d",
		env->cycle_to_die - cycles_left, env->cycle_to_die);
	mvprintw(LINES - 7, 5, " Total cycles : %d", env->cycle);
	return (0);
}
