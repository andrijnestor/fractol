/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:00:12 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 14:00:40 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		iter_mandelbrot(t_ftl *ftl, double pr, double pi)
{
	double	newRe;
   	double	newIm;
	double	oldRe;
	double	oldIm;
	int		i;

	newRe = 0;
	newIm = 0;
	oldRe = 0;
	oldIm = 0;
	i = 0;
	while (i < ftl->maxIter)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + pr;
		newIm = 2 * oldRe * oldIm + pi;
		if ((newRe * newRe + newIm * newIm) > 4)
			break ;
		i++;
	}
//	printf("i: %d ", i); //
	return (i);
}

void	put_mandelbrot(t_ftl *ftl)
{
	double	pr;
	double	pi;
//	int		col;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < ftl->winH)
	{
		x = 0;
		while (x < ftl->winW)
		{
			pr = 1.5 * (x - ftl->winW / 2) / (0.5 * ftl->zoom * ftl->winW);
			pr = pr + ftl->moveX;
			pi = (y - ftl->winH / 2) / (0.5 * ftl->zoom * ftl->winH);
			pi = pi + ftl->moveY;
			i = iter_mandelbrot(ftl, pr, pi);
		//	if (i != ftl->maxIter)
		//		col = color(0xff0000, 0xffff00, test_color(i, ftl));
		//	else
		//		col = 0x000000;
		//	printf("col: %X ", col);
		//	mlx_pixel_put(ftl->mlx, ftl->win, x, y, col);
		//	if (i < ftl->maxIter)
			xpm_pixel_put(ftl, x, y, i);
			x++;
		}
		y++;
	}
}
