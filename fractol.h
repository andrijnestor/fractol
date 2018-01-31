/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:23 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 15:19:31 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <string.h> // check all includes
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "libft/libft.h"
# include <stdio.h>//
# include <time.h>
# define COLOR_N 100
# define WIN_H 1000
# define WIN_W 1000
# define DEPTH 1000
# define THREADS 8

typedef struct	s_imre
{
	double		im;
	double		re;
}				t_imre;

typedef struct	s_ftl
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**xpm;
	double		moveX;
	double		moveY;
	double		zoom;
	int			maxIter;
	int			winH;
	int			winW;
	int			colDepth;
	int			core;
}				t_ftl;

t_ftl			*ftl_init(void);
void			create_xpm(t_ftl *ftl);


void	xpm_pixel_put(t_ftl *ftl, int x, int y, int col);

/*
** mandelbrot
*/

void	put_mandelbrot(t_ftl *ftl);

/*
** colors
*/

void	color_range_init(t_ftl *ftl);

#endif
