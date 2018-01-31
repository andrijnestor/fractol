/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:41:38 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 17:16:42 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		iter_mandelbrot(t_ftl *ftl, double pr, double pi)
{
	t_imre	new;
	t_imre	old;
	int		i;

	ft_bzero(&new, sizeof(t_imre));
	ft_bzero(&old, sizeof(t_imre));
	i = 0;
	while (i < ftl->maxIter)
	{
		old.re = new.re;
		old.im = new.im;
		new.re = old.re * old.re - old.im * old.im + pr;
		new.im = 2 * old.re * old.im + pi;
		if ((new.re * new.re + new.im * new.im) > 4)
			break ;
		i++;
	}
	return (i);
}

void	*put_mandelbrot_per_core(void *arg)
{
	t_imre	p;
	int		x;
	int		y;
	t_ftl	*ftl;
	int		core;

	ftl = (t_ftl *)arg;
	core = ftl->core++;
	y = ftl->winH / THREADS * core;
	while (y < ftl->winH / THREADS * (core + 1))
	{
		x = 0;
		while (x < ftl->winW)
		{
			p.re = 1.5 * (x - ftl->winW / 2) / (0.5 * ftl->zoom * ftl->winW);
			p.re = p.re + ftl->moveX;
			p.im = (y - ftl->winH / 2) / (0.5 * ftl->zoom * ftl->winH);
			p.im = p.im + ftl->moveY;
			xpm_pixel_put(ftl, x, y, iter_mandelbrot(ftl, p.re, p.im));
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

void	put_mandelbrot(t_ftl *ftl)
{
	int			i;
	pthread_t	tid[THREADS];

	i = 0;
	ftl->core = 0;
	while (i != THREADS)
	{
		while (ftl->core != i)
			;
		pthread_create(&tid[i], NULL, put_mandelbrot_per_core, ftl);
		i++;
	}
	i = 0;
	while (i != THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}
