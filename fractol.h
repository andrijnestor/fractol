/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:23 by anestor           #+#    #+#             */
/*   Updated: 2018/02/09 00:49:55 by anestor          ###   ########.fr       */
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
//# define COLOR_N 256
//# define COLOR_RANGE 10
# define WIN_H 600
# define WIN_W 800
# define THREADS 8
# define F_ZM ftl->zoom

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

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			last_x;
	int			last_y;
	char		is_down;
}				t_mouse;

typedef struct	s_ftl
{
	void		*mlx;
	void		*win;
	int			type;
	double		move_x;
	double		move_y;
	double		zoom;
	int			max_iter;
	int			win_h;
	int			win_w;
	int			thread;
	int			col_depth;
	int			col1;
	int			col2;
	t_img		img;
	t_mouse		mouse;
}				t_ftl;

/*
** init
*/

int				ftl_usage(void);
int				fractol_make(char *name);
void			fractol_render(t_ftl *ftl);
t_ftl			*ftl_init(int type, char *name);

/*
** images
*/

void			create_img(t_ftl *ftl);
void			img_pixel_put(t_ftl *ftl, int x, int y, int col);
void			put_img(t_ftl *ftl);

/*
** fractals
*/

void			put_mandelbrot(t_ftl *ftl);
void			put_julia(t_ftl *ftl);
void			put_ship(t_ftl *ftl);
void			put_fractol(t_ftl *ftl);

/*
** hooks
*/

int				key_hooks(int keycode, t_ftl *ftl);
int				hook_mouse_down(int keycode, int x, int y, t_ftl *ftl);
int				hook_mouse_up(int keycode, int x, int y, t_ftl *ftl);
int				hook_mouse_move(int x, int y, t_ftl *ftl);
int				exit_on_x(void *tmp);

#endif
