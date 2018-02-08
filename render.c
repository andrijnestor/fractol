/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:29:13 by anestor           #+#    #+#             */
/*   Updated: 2018/02/09 00:15:30 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render(t_ftl *ftl)
{
	mlx_destroy_image(ftl->mlx, ftl->img.image);
	create_img(ftl);
	put_fractol(ftl);
	put_img(ftl);
}
