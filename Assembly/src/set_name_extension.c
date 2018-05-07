/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_name_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:31:13 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 16:04:59 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		remplace .s par .cor
*/

char	*set_name_cor(char *name)
{
	char *file_cor;
	char *tmp;

	tmp = ft_strnew(ft_strlen(name) - 2);
	tmp = ft_strncpy(tmp, name, (ft_strlen(name) - 2));
	file_cor = ft_strjoin(tmp, ".cor");
	ft_strdel(&tmp);
	return (file_cor);
}

/*
**		verif extension du fichier demande
*/

int		ft_check_ext(char *str)
{
	if ((str[ft_strlen(str) - 1] == 's') && (str[ft_strlen(str) - 2] == '.'))
		return (1);
	else
	{
		ft_printf("\033[31mError\033[00m : \"%s\" is not a .s\n", str);
		return (0);
	}
	return (0);
}
