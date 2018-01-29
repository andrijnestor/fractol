/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:23 by anestor           #+#    #+#             */
/*   Updated: 2018/01/29 17:08:51 by anestor          ###   ########.fr       */
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
# include "libft/libft.h"
# include <stdio.h>//
# define DEPTH 1000

typedef struct	s_ftl
{
	void		*mlx;
	void		*win;
	double		moveX;
	double		moveY;
	double		zoom;
	int			maxIter;
	int			winH;
	int			winW;
}				t_ftl;

t_ftl			*ftl_init(void);

#endif
