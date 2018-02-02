/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:23 by anestor           #+#    #+#             */
/*   Updated: 2018/02/02 23:51:19 by anestor          ###   ########.fr       */
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
# include <time.h> //
# define COLOR_N 256
# define COLOR_RANGE 10
# define WIN_H 600
# define WIN_W 800
# define THREADS 200

typedef struct	s_imre
{
	double		im;
	double		re;
}				t_imre;

typedef struct	s_img
{
	void		*image;
	char		*addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_ftl
{
	void		*mlx;
	void		*win;
//	void		*img;
	char		**xpm;
	double		moveX;
	double		moveY;
	double		zoom;
	int			maxIter;
	int			winH;
	int			winW;
	int			colDepth;
	int			colRange;
	int			core;
	t_img		*img;
}				t_ftl;

/*
** init
*/

t_ftl			*ftl_init(void);

/*
** images xpm
*/

void			create_xpm(t_ftl *ftl);
void			xpm_pixel_put(t_ftl *ftl, int x, int y, int col);
void			put_image(t_ftl *ftl);

/*
** images
*/

void			create_img(t_ftl *ftl);
void			img_pixel_put(t_ftl *ftl, int x, int y, int col, t_imre p);
void			put_img(t_ftl *ftl);


/*
** fractals
*/

void			put_mandelbrot(t_ftl *ftl);
void			put_julia(t_ftl *ftl);

/*
** colors
*/

void			color_range_init(t_ftl *ftl);

/*
** hooks
*/

int				key_hooks(int keycode, t_ftl *ftl);

#endif
