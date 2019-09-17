/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 16:05:39 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:32:13 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			check_ants_for_char(char *line, t_lem *lem)
{
	int		flag;

	flag = 0;
	while (*line)
	{
		if (*line > '0' && *line <= '9')
			flag = 1;
		if (*line < '0' || *line > '9')
		{
			print_error_ants();
			free_lem(lem);
		}
		line++;
	}
}

void			check_ants_amount(t_lem *lem)
{
	char		*line;

	get_next_line((*lem).fd, &line);
	check_ants_for_char(line, lem);
	(*lem).map_info = ft_strdup(line);
	(*lem).ants_amount = ft_atoi(line);
	ft_strdel(&line);
	if ((*lem).ants_amount < 1)
	{
		print_error_ants();
		free_lem(lem);
	}
}
