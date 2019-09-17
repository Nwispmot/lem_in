/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluton <hluton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:08:03 by hluton            #+#    #+#             */
/*   Updated: 2018/12/22 20:09:02 by hluton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int		i;
	int		sum;
	char	*ptr;
	int		flag;

	flag = 0;
	ptr = (char *)nptr;
	sum = 0;
	i = 0;
	while ((ptr[i] <= 13 && ptr[i] >= 9) || ptr[i] == 32)
		i++;
	if (ptr[i] == '-')
		flag = 1;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		sum = (sum * 10 + (ptr[i] - 48));
		i++;
	}
	if (flag)
		return (sum * (-1));
	return (sum);
}
