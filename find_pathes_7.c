/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pathes_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:57:12 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 21:36:25 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			clear_room_array_copy_2(t_room *tmp)
{
	free_connections(tmp);
	ft_strdel(&tmp->name);
	ft_bzero(tmp, sizeof(t_room));
}

void			clear_room_array_copy(t_lem *lem)
{
	int		i;
	t_room	*tmp;
	t_room	*hash_tmp;

	i = 0;
	while (i < ARRAY_SIZE - 302)
	{
		tmp = &lem->room_array_copy[i];
		if (tmp->name)
		{
			if (!tmp->next_hash)
				clear_room_array_copy_2(tmp);
			else
			{
				while (tmp->next_hash)
				{
					hash_tmp = tmp->next_hash;
					clear_room_array_copy_2(tmp);
					tmp = hash_tmp;
				}
			}
		}
		i++;
	}
}

void			initialize_pathes_lengthes(t_lem *lem)
{
	int		i;

	i = 0;
	while (lem->pathes_lengthes[i])
		lem->pathes_lengthes = 0;
}

void			restore_path_2(t_lem *lem, char **split, char **ret, int *i)
{
	if (strstr(split[*i], "in"))
	{
		if (find_room_copy_by_name(split[*i], &lem)->is_double == 1)
			*ret = ft_strjoin_free(*ret, ft_strsub(split[*i],
			0, ft_strlen(split[*i]) - 2), 1, 1);
	}
	else if (strstr(split[*i], "out"))
	{
		if (find_room_copy_by_name(split[*i], &lem)->is_double == 1)
			*ret = ft_strjoin_free(*ret, ft_strsub(split[*i],
			0, ft_strlen(split[*i]) - 3), 1, 1);
	}
	else
		*ret = ft_strjoin_free(*ret, split[*i], 1, 0);
	*ret = ft_strjoin_free(*ret, " ", 1, 0);
}

void			clear_room_stack(t_lem *lem)
{
	char	**temp;
	int		i;

	i = 0;
	temp = lem->room_stack;
	while (temp[i])
	{
		ft_strdel(&temp[i]);
		i++;
	}
}
