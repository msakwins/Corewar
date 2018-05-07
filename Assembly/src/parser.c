/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:16:24 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 16:03:36 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		verif_jump(char *line, int nb_param)
{
	int	jump;
	int	i;

	jump = 0;
	i = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
	{
		if (line[i] == SEPARATOR_CHAR)
			jump++;
		i++;
	}
	if (jump > nb_param - 1)
		return (0);
	return (1);
}

/*
**		transforme tout les \t en espace
*/

char	*ft_clear_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			s[i] = ' ';
		i++;
	}
	return (s);
}

/*
**		lis le fichier correspondant au fd
** 		saute toutes les lignes commencant par "#"
** 		enregistre les deux premierieres lignes dans t_file_list header
** 		le reste dans t_file_list body
*/

void	set_file_list(t_asm *param, int fd)
{
	char		*line;
	int			num_l;
	t_file_list *header_list;
	t_file_list *body_list;

	line = NULL;
	num_l = 1;
	header_list = NULL;
	body_list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (verif_line(line))
		{
			line = ft_clear_str(line);
			if (size_list(&header_list) < 2)
				ft_add_end_file_list(&header_list, line, num_l);
			else
				ft_add_end_file_list(&body_list, line, num_l);
		}
		num_l++;
		ft_strdel(&line);
	}
	param->header = header_list;
	param->body = body_list;
}

/*
**		Fonction controlant le parsing de tout le fichier
** 		ouvre le fd correspondant					ft_open_file
** 		recupere les deux list header et body 		set_file_list
** 		analyse le header 							set_name_comment
** 		analyse le body 							ft_parse_body
*/

int		ft_parser(t_asm *param)
{
	int	fd;

	fd = ft_open_file(param->file_s);
	set_file_list(param, fd);
	set_name_comment(param);
	free_file_list(&param->header);
	if (!ft_parse_body(param))
		exit_msg_error(param, "Parser", -1);
	if (param->err == 1)
		return (0);
	return (1);
}
