/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 00:02:53 by anestor           #+#    #+#             */
/*   Updated: 2018/02/09 00:07:29 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iter_julia(t_ftl *ftl, double real, double imag)
{
	t_imre	new;
	t_imre	old;
	int		i;

	ft_bzero(&old, sizeof(t_imre));
	new.re = real;
	new.im = imag;
	i = 0;
	while (i < ftl->max_iter)
	{
		old.re = new.re;
		old.im = new.im;
		new.re = old.re * old.re - old.im * old.im +
			((double)(ftl->mouse.x - WIN_W / 2) / WIN_W);
		new.im = 2 * old.re * old.im +
			((double)(ftl->mouse.y - WIN_H / 2) / WIN_H);
		if ((new.re * new.re + new.im * new.im) > 4)
			break ;
		i++;
	}
	return (i);
}

static int	iter_mandelbrot(t_ftl *ftl, double pr, double pi)
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

static int	iter_ship(t_ftl *ftl, double pr, double pi)
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
		old.re = fabs(old.re);
		old.im = fabs(old.im);
		new.re = old.re * old.re - old.im * old.im + pr;
		new.im = 2 * old.re * old.im + pi;
		if ((new.re * new.re + new.im * new.im) > 4)
			break ;
		i++;
	}
	return (i);
}

static void	*put_fract_per_thread(void *arg)
{
	t_imre	p;
	int		x;
	int		y;
	t_ftl	*ftl;
	int		thread;

	ftl = (t_ftl *)arg;
	thread = ftl->thread++;
	y = ftl->win_h / THREADS * thread - 1;
	while (++y < ftl->win_h / THREADS * (thread + 1))
	{
		x = -1;
		while (++x < ftl->win_w)
		{
			p.re = 1.5 * (x - WIN_W / 2) / (0.5 * F_ZM * WIN_W) + ftl->move_x;
			p.im = (y - WIN_H / 2) / (0.5 * F_ZM * WIN_H) + ftl->move_y;
			if (ftl->type == 2)
				img_pixel_put(ftl, x, y, iter_ship(ftl, p.re, p.im));
			else if (ftl->type == 1)
				img_pixel_put(ftl, x, y, iter_julia(ftl, p.re, p.im));
			else
				img_pixel_put(ftl, x, y, iter_mandelbrot(ftl, p.re, p.im));
		}
	}
	pthread_exit(0);
}

void		put_fractol(t_ftl *ftl)
{
	int				i;
	pthread_t		tid[THREADS];
	pthread_mutex_t mutex;
	pthread_cond_t	cv;

	i = 0;
	ftl->thread = 0;
	while (i != THREADS)
	{
		pthread_create(&tid[i], NULL, put_fract_per_thread, ftl);
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
