/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:37:20 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 17:01:14 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			write_line_to_info(char *line, t_lem *lem)
{
	char	*temp;

	if (lem->map_info == NULL)
		lem->map_info = ft_strdup(line);
	else
	{
		temp = ft_strjoin((*lem).map_info, line);
		ft_strdel(&((*lem).map_info));
		(*lem).map_info = temp;
	}
}

void			parse_map_2(t_lem *lem, char **line)
{
	if (*line[0] == '#' && *line[1] != '#')
	{
		write_line_to_info("\n", lem);
		write_line_to_info(*line, lem);
		return ;
	}
	if (ft_strchr(*line, '-'))
		check_connections(lem, *line);
	else
		parse_room(*line, lem);
}

void			manage_start_end(char **line, t_lem *lem)
{
	if (ft_strcmp(*line, "##start") == 0)
	{
		lem->starts++;
		write_line_to_info("\n", lem);
		write_line_to_info(*line, lem);
		(*lem).is_start = 1;
		ft_strdel(&(*line));
		get_next_line((*lem).fd, &(*line));
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		lem->ends++;
		write_line_to_info("\n", lem);
		write_line_to_info(*line, lem);
		(*lem).is_end = 1;
		ft_strdel(&(*line));
		get_next_line((*lem).fd, &(*line));
	}
	else
		print_error_comment();
}

void			parse_map(t_lem *lem)
{
	char	*line;

	while (get_next_line((*lem).fd, &line) > 0)
	{
		(*lem).is_end = 0;
		(*lem).is_start = 0;
		if (line[0] == '\0')
			break ;
		if (line[0] == '#' && line[1] == '#')
		{
			manage_start_end(&line, lem);
		}
		parse_map_2(lem, &line);
		ft_strdel(&line);
	}
}

void			validate_map(t_lem *lem)
{
	check_ants_amount(lem);
	parse_map(lem);
	if (lem->starts != 1 || lem->ends != 1)
		print_error_room();
}
