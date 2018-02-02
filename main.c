/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:00 by anestor           #+#    #+#             */
/*   Updated: 2018/02/02 22:04:11 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	create_img(ftl);
//	printf("%s\n", ftl->img->addr);
	color_range_init(ftl);
	put_mandelbrot(ftl);
//	print_xpm(ftl);
//	put_image(ftl);
//	ft_memset(ftl->img->addr, '1', WIN_W * WIN_H);
//	printf("ihere: %s\n", ftl->img->addr);
	put_img(ftl);
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
	ftl->colDepth = 1;
	ftl->colRange = 1;
	return(ftl);
}
