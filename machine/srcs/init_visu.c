/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:20:54 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:06:43 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	init_curse_color(void)
{
	initscr();
	start_color();
	init_color(COLOR_WHITE, 220, 220, 220);
	init_color(COLOR_GREEN, 150, 150, 150);
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_GREEN, COLOR_BLACK);
	curs_set(FALSE);
}

void	end_curses(t_env *env)
{
	sleep(3);
	erase();
	refresh();
	mvprintw(LINES / 2 - 5, COLS / 2 - 20,
		"Contestant %d, \"%s\", has won !\n", env->player[env->winner].nb,
		env->player[env->winner].header->prog_name);
	refresh();
	sleep(5);
	endwin();
}
