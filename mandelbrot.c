/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:41:38 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 03:27:11 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		iter_mandelbrot(t_ftl *ftl, double pr, double pi)
{
	t_imre	new;
	t_imre	old;
	int		i;

	ft_bzero(&new, sizeof(t_imre));
	ft_bzero(&old, sizeof(t_imre));
	i = 0;
	while (i < ftl->max_iter)
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

static void		*put_mandelbrot_per_core(void *arg)
{
	t_imre	p;
	int		x;
	int		y;
	t_ftl	*ftl;
	int		thread;

	ftl = (t_ftl *)arg;
	thread = ftl->thread++;
	y = ftl->win_h / THREADS * thread;
	while (y < ftl->win_h / THREADS * (thread + 1))
	{
		x = 0;
		while (x < ftl->win_w)
		{
			p.re = 1.5 * (x - ftl->win_w / 2) / (0.5 * ftl->zoom * ftl->win_w);
			p.re = p.re + ftl->move_x;
			p.im = (y - ftl->win_h/ 2) / (0.5 * ftl->zoom * ftl->win_h);
			p.im = p.im + ftl->move_y;
			img_pixel_put(ftl, x, y, iter_mandelbrot(ftl, p.re, p.im));
			x++;
		}
		y++;
	}
	pthread_exit(0);
}

void	put_mandelbrot(t_ftl *ftl)
{
	int				i;
	pthread_t		tid[THREADS];
	pthread_mutex_t mutex;
	pthread_cond_t	cv;

	i = 0;
	ftl->thread = 0;
	while (i != THREADS)
	{
		pthread_create(&tid[i], NULL, put_mandelbrot_per_core, ftl);
		i++;
		while (ftl->thread != i)
			pthread_cond_wait(&cv, &mutex);
		pthread_cond_signal(&cv);
	}
	i = 0;
	while (i != THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
}
