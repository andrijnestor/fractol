/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:27:29 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 20:27:50 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hooks(int keycode, t_ftl *ftl)
{
	(void)ftl;
	if (keycode == 124)
		ftl->moveX += 0.1 / ftl->zoom;
	if (keycode == 123)
		ftl->moveX -= 0.1 / ftl->zoom;
	if (keycode == 126)
		ftl->moveY -= 0.1 / ftl->zoom;
	if (keycode == 125)
		ftl->moveY += 0.1 / ftl->zoom;
	if (keycode == 69)
		ftl->zoom *= 1.1;
	if (keycode == 18)
		ftl->maxIter -= 10;
	if (keycode == 19)
		ftl->maxIter += 10;
	if (keycode == 20)
		ftl->colDepth -= 10;
	if (keycode == 21)
		ftl->colDepth += 10;
	if (keycode == 23)
	{
		if (ftl->colRange > 1)
		{
			ftl->colRange--;
			color_range_init(ftl);
		}
	}
	if (keycode == 22)
	{
		ftl->colRange++;
		color_range_init(ftl);
	}
	if (keycode == 78)
		ftl->zoom /= 1.1;
	if (keycode == 53)
		exit(0);
//	mlx_clear_window(ftl->mlx, ftl->win);

	clock_t begin = clock();
//	put_mandelbrot(ftl);
	put_julia(ftl);
	clock_t end = clock();
	printf("Formula time: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	begin = clock();
	mlx_destroy_image(ftl->mlx, ftl->img);
	put_image(ftl);
	end = clock();
	printf("Image time: %f\n", (double)(end - begin) / CLOCKS_PER_SEC);

	printf("colRange: %d\n", ftl->colRange);
	printf("iter: %d\n", ftl->maxIter);
	printf("k: %d\n", keycode);
	return (0);
}
