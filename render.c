/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:29:13 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 03:27:16 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_put(t_ftl *ftl)
{
	mlx_destroy_image(ftl->mlx, ftl->img.image);
	create_img(ftl);
	if (ftl->type == 0)
		put_mandelbrot(ftl);
	else if (ftl->type == 1)
		put_julia(ftl);
	put_img(ftl);
}
