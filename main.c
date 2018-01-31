/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:00 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 18:10:22 by anestor          ###   ########.fr       */
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

double	test_color(int i, t_ftl *ftl)
{
	double k;
	double j;

	j = i % 256;
	if (j < 100)
		k = j / 100;
	else
		k = j / 1000;
//	if (k >= 1)
//	printf("%f ", fmod(k * ftl->colDepth, 1.0));
	return (fmod(k * ftl->colDepth, 1.0));
}

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
		ftl->colDepth--;
	if (keycode == 21)
		ftl->colDepth++;
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
	put_mandelbrot(ftl);
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

void	print_xpm(t_ftl *ftl)
{
	int		i;

	i = 0;
	while (i != (COLOR_N + WIN_H + 2))
	{
		printf("line: %s\n", ftl->xpm[i]);
		i++;
	}
}

int		main(void)
{
	t_ftl	*ftl;

//	printf("%x\n", color(0xffffff, 0xffff00, 0.1));
	ftl = ftl_init();
	create_xpm(ftl);
	color_range_init(ftl);
	put_mandelbrot(ftl);
//	print_xpm(ftl);
	put_image(ftl);
	mlx_hook(ftl->win, 2, 5, key_hooks, ftl);
	mlx_loop(ftl->mlx);
	return (0);
}

t_ftl	*ftl_init(void)
{
	t_ftl	*ftl;

	ftl = malloc(sizeof(t_ftl));
	ftl->mlx = mlx_init();
	ftl->winH = WIN_H;
	ftl->winW = WIN_W;
	ftl->win = mlx_new_window(ftl->mlx, ftl->winW, ftl->winH, "fractol");
	ftl->zoom = 1;
	ftl->moveX = -0.5;
	ftl->moveY = 0;
	ftl->maxIter = 50;
	ftl->colDepth = 2;
	ftl->colRange = 1;
	return(ftl);
}
