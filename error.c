/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:06:41 by hluton            #+#    #+#             */
/*   Updated: 2019/09/10 15:30:08 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void			print_error_comment(void)
{
	ft_putstr("error: comment is not set properly.");
	exit(0);
}

void			print_error_ants(void)
{
	ft_putstr("error: ants' amount is not set properly.");
	exit(0);
}

void			print_error_room(void)
{
	ft_putstr("error: room is not set properly.");
	exit(0);
}

void			print_error_solution(void)
{
	ft_putstr("error: no way out. Holy shit:/");
	exit(0);
}
