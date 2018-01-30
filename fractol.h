/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:23 by anestor           #+#    #+#             */
/*   Updated: 2018/01/30 23:39:47 by anestor          ###   ########.fr       */
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
}				t_ftl;

t_ftl			*ftl_init(void);
void			create_xpm(t_ftl *ftl);

/*
** colors
*/

void	color_range_init(t_ftl *ftl);

#endif
