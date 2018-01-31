/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:31:46 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 17:20:44 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	color_grad(int start, int end, double perc)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * perc));
}

static int	rgb_grad(int c1, int c2, double perc)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = color_grad((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, perc);
	g = color_grad((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, perc);
	b = color_grad(c1 & 0xFF, c2 & 0xFF, perc);
	return (r << 16 | g << 8 | b);
}

static void	color_range(int col1, int col2, t_ftl *ftl)
{
	int		i;
	char	*tmp;

	i = 1;
	while (i != COLOR_N + 1)
	{
		tmp = ft_itoa_base_int(rgb_grad(col1, col2, (double)i / COLOR_N), 16);
		ft_memcpy(&ftl->xpm[i][6], tmp, 6);
		free(tmp);
		i++;
	}
}

void		color_range_init(t_ftl *ftl)
{
	if (ftl->colRange % COLOR_RANGE == 1)
		color_range(0xFF0000, 0xFFFF00, ftl);
	else if (ftl->colRange % COLOR_RANGE == 2)
		color_range(0xFF0000, 0xFF0000, ftl);
	else if (ftl->colRange % COLOR_RANGE == 3)
		color_range(0xFF0000, 0x00FFFF, ftl);
	else if (ftl->colRange % COLOR_RANGE == 4)
		color_range(0x000000, 0xFFFFFF, ftl);
	else if (ftl->colRange % COLOR_RANGE == 5)
		color_range(0x555555, 0x000000, ftl);
	else if (ftl->colRange % COLOR_RANGE == 6)
		color_range(0x0000FF, 0xFFFF00, ftl);
	else if (ftl->colRange % COLOR_RANGE == 7)
		color_range(0x00FF00, 0xFFFF00, ftl);
	else if (ftl->colRange % COLOR_RANGE == 8)
		color_range(0x00FF00, 0x0000FF, ftl);
	else if (ftl->colRange % COLOR_RANGE == 9)
		color_range(0x0000FF, 0xFFFFfF, ftl);
	else if (ftl->colRange % COLOR_RANGE == 0)
		color_range(0xFFFFFF, 0x00FF00, ftl);
}
