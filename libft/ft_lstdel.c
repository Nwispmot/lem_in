/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:55:51 by hluton            #+#    #+#             */
/*   Updated: 2018/12/29 18:20:13 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	ptr = *alst;
	while ((*alst)->next != NULL)
	{
		ft_lstdelone(&ptr, del);
		*alst = (*alst)->next;
	}
	ft_lstdelone(alst, del);
}
