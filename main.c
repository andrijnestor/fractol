/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:00 by anestor           #+#    #+#             */
/*   Updated: 2018/01/29 20:59:13 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_grad(int start, int end, double perc)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * perc));
}

int		color(int c1, int c2, double perc)
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
	int		col;
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
			if (i != ftl->maxIter)
				col = color(0xff0000, 0xffffff, i / 10);
			else
				col = 0x000000;
		//	printf("col: %X ", col);
			mlx_pixel_put(ftl->mlx, ftl->win, x, y, col);
			x++;
		}
		y++;
	}
}

int		key_hooks(int keycode, t_ftl *ftl)
{
	(void)ftl;
	if (keycode == 124)
		ftl->moveX += 0.1 / ftl->zoom;
	if (keycode == 123)
		ftl->moveX -= 0.1 / ftl->zoom;
	if (keycode == 126)
		ftl->moveY -= 0.1 / ftl->zoom;
	if (keycode == 125)
		ftl->moveY += 0.1 / ftl->zoom;
	if (keycode == 69)
		ftl->zoom *= 1.1;
	if (keycode == 78)
		ftl->zoom /= 1.1;
	if (keycode == 53)
		exit(0);
	mlx_clear_window(ftl->mlx, ftl->win);
	put_mandelbrot(ftl);
	printf("k: %d\n", keycode);
	return (0);
}

int		main(void)
{
	t_ftl	*ftl;

	printf("%x\n", color(0xffffff, 0x00ffff, 0.1));
	ftl = ftl_init();
	put_mandelbrot(ftl);
	mlx_hook(ftl->win, 2, 5, key_hooks, ftl);
	mlx_loop(ftl->mlx);
	return (0);
}

t_ftl	*ftl_init(void)
{
	t_ftl	*ftl;

	ftl = malloc(sizeof(t_ftl));
	ftl->mlx = mlx_init();
	ftl->winH = 500;
	ftl->winW = 500;
	ftl->win = mlx_new_window(ftl->mlx, ftl->winW, ftl->winH, "fractol");
	ftl->zoom = 1;
	ftl->moveX = -0.5;
	ftl->moveY = 0;
	ftl->maxIter = 300;
	return(ftl);
}
