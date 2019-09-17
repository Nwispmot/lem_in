/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lem_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:23:53 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 16:24:00 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int				is_everybody_home(t_lem *lem)
{
	t_ants *ptr;

	ptr = lem->ants_head;
	while (ptr)
	{
		if (*(ptr->path + 1))
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
