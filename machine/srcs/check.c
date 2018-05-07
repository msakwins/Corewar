/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:20:54 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/19 23:35:27 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void			check_number(t_env *e, char *nb)
{
	char	*numbers;
	int		i;

	numbers = "0123456789";
	i = -1;
	while (nb[++i])
		if (!(ft_strchr(numbers, nb[i])))
			ft_exit(e, 1, "Wrong value");
	if (ft_strlen(nb) > 7)
		ft_exit(e, 1, "Too big -n");
}

void			check_dup_number(t_env *env, int nb)
{
	int		i;

	i = 0;
	while (i < env->nb_players)
	{
		if (nb == env->player[i].nb)
			ft_exit(env, 2, "Players can't have the same number");
		i++;
	}
}
