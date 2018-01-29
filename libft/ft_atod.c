/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:30:10 by anestor           #+#    #+#             */
/*   Updated: 2017/11/02 20:57:54 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *str)
{
	double	num;
	double	afterdot;
	long	aftersize;
	int		neg;

	neg = 1;
	num = ft_atoi(str);
	while (*str != '.' && str++ != '\0')
		if (*str == '\0')
			return (num);
	if (*(str) == '.')
		afterdot = ft_atoi(++str);
	else
		afterdot = 0;
	aftersize = 10;
	while (afterdot / aftersize >= 1)
		aftersize *= 10;
	afterdot = afterdot / aftersize;
	if (num < 0)
		num = num - afterdot;
	else
		num = num + afterdot;
	return (num);
}
