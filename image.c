/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:09:28 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 02:29:46 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color_grad(int start, int end, double perc)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * perc));
}

int		color(int c1, int c2, double perc)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = color_grad((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, perc);
	g = color_grad((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, perc);
	b = color_grad(c1 & 0xFF, c2 & 0xFF, perc);
	return (r << 16 | g << 8 | b);
}

void	img_pixel_put(t_ftl *ftl, int x, int y, int col)
{
	double	dcolor;

	if (col >= ftl->max_iter)
		*(int *)(ftl->img.addr + ((x + y * WIN_W) * sizeof(int))) = 0;
	else
	{
		col = col * ftl->col_depth % ftl->max_iter;
		dcolor = col;
		dcolor = color(ftl->col1, ftl->col2, (double)(dcolor / ftl->max_iter));
		*(int *)(ftl->img.addr + ((x + y * WIN_W) * sizeof(int))) = dcolor;
	}
}

void	put_img(t_ftl *ftl)
{
	mlx_put_image_to_window(ftl->mlx, ftl->win, ftl->img.image, 0, 0);
}

void	create_img(t_ftl *ftl)
{
	ftl->img.image = mlx_new_image(ftl->mlx, WIN_W, WIN_H);
	ftl->img.addr = mlx_get_data_addr(ftl->img.image, &ftl->img.bpp, 
			&ftl->img.size_line, &ftl->img.endian);
	ftl->img.bpp /= 8;
}

