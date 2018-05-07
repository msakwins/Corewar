/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 10:34:47 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 16:04:23 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
** 	ecrit :
**		-name_prg (complete de '\0' si necessaire)
** 		-8 * '\0'
** 		-comment_prg (complete de '\0' si necessaire)
*/

void	print_header(t_asm *param)
{
	int	len;

	len = ft_strlen(param->name_prg);
	write(param->fd, param->name_prg, ft_strlen(param->name_prg));
	while (++len <= PROG_NAME_LENGTH)
		write(param->fd, "\0", 1);
	write(param->fd, "\0\0\0\0\0\0\0\0", 8);
	len = ft_strlen(param->comment_prg);
	write(param->fd, param->comment_prg, ft_strlen(param->comment_prg));
	while (++len <= COMMENT_LENGTH)
		write(param->fd, "\0", 1);
	write(param->fd, "\0\0\0\0", 4);
}

/*
**		ecrit le COREWAR_EXEC_MAGIC : 0xea83f3
*/

void	print_magic(int fd)
{
	int		magic[4];
	int		mag;
	int		i;

	i = -1;
	mag = COREWAR_EXEC_MAGIC;
	while (++i < 4)
	{
		magic[i] = (unsigned char)mag;
		mag >>= 8;
	}
	while (--i >= 0)
		write(fd, &magic[i], 1);
}
