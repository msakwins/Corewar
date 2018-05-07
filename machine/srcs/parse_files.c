/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:25:46 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/11 23:08:06 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Credits to
** https://stackoverflow.com/questions/2182002
*/

static int		invert_endian(int x)
{
	int		new_x;

	new_x = ((x >> 24) & 0xff) |
		((x << 8) & 0xff0000) |
		((x >> 8) & 0xff00) |
		((x << 24) & 0xff000000);
	return (new_x);
}

static void		verify_header(t_header *header, t_env *e)
{
	if (header->prog_size > CHAMP_MAX_SIZE)
		ft_exit(e, 1, "Champ file too large");
	if (header->magic != COREWAR_EXEC_MAGIC)
		ft_exit(e, 1, "Magic is not the good one");
}

static void		parse_header(t_env *e, int fd, int curr_player)
{
	t_header	*header;

	if ((header = (t_header *)malloc(sizeof(t_header))) == NULL)
		ft_exit(e, 1, "Malloc failed");
	if (read(fd, header, sizeof(t_header)) == -1)
		ft_exit(e, 1, "Cant read player file");
	header->prog_size = invert_endian(header->prog_size);
	header->magic = invert_endian(header->magic);
	verify_header(header, e);
	e->player[curr_player].header = header;
}

static void		parse_instructions(t_env *e, int fd, int curr_player)
{
	unsigned int	size;

	size = e->player[curr_player].header->prog_size;
	if (!(e->player[curr_player].code = (char *)malloc(size)))
		ft_exit(e, 1, "Malloc for player code failed");
	if (!read(fd, e->player[curr_player].code, size))
		ft_exit(e, 1, "Read player code failed");
}

/*
** Read files and create header and codes of champs
** in the t_header and a char *code
*/

void			parse_files(t_env *e, char **argv)
{
	int i;
	int fd;

	i = 0;
	while (i < e->nb_players)
	{
		if (ft_strlen(argv[e->player[i].file_pos]) <= 4 ||
				ft_strcmp(argv[e->player[i].file_pos] +
					ft_strlen(argv[e->player[i].file_pos]) - 4, ".cor"))
			ft_exit(e, 2, "Not a .cor file");
		if ((fd = open(argv[e->player[i].file_pos], O_RDONLY)) == -1)
			ft_exit(e, 1, "Open error");
		parse_header(e, fd, i);
		parse_instructions(e, fd, i);
		e->player[i].live = 0;
		if (close(fd) == -1)
			ft_exit(e, 1, "Close error");
		i++;
	}
}
