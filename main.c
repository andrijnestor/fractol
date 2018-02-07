/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:00 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 16:54:07 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	if (argc < 2 || argc > 3)
		return (0);
	else
	{
		if (argc == 3)
			fork();
		if (getpid() == pid && argc == 3)
			fractol_make(argv[2]);
		else
			fractol_make(argv[1]);
	}
	return (0);
}

void	fractol_make(char *name)
{
	t_ftl	*ftl;
	int		type;

	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "-m"))
		type = 0;
	else if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "-j"))
		type = 1;
	else
		return ;
	ftl = ftl_init(type, name);
	create_img(ftl);
	if (type == 0)
		put_mandelbrot(ftl);
	else if (type == 1)
		put_julia(ftl);
	put_img(ftl);
	mlx_hook(ftl->win, 2, 5, key_hooks, ftl);
	mlx_hook(ftl->win, 4, 0, hook_mouse_down, ftl);
	mlx_hook(ftl->win, 5, 0, hook_mouse_up, ftl);
	mlx_hook(ftl->win, 6, 0, hook_mouse_move, ftl);
	mlx_hook(ftl->win, 17, 1L << 17, exit_on_x, NULL);
	mlx_loop(ftl->mlx);
}

t_ftl	*ftl_init(int type, char *name)
{
	t_ftl	*ftl;

	ftl = malloc(sizeof(t_ftl));
	ftl->type = type;
	ftl->mlx = mlx_init();
	ftl->win_h = WIN_H;
	ftl->win_w = WIN_W;
	ftl->win = mlx_new_window(ftl->mlx, ftl->win_w, ftl->win_h, name);
	ftl->zoom = 1;
	if (type == 0)
		ftl->move_x = -0.5;
	else
		ftl->move_x = 0;
	ftl->move_y = 0;
	ftl->max_iter = 50;
	ftl->col_depth = 1;
	ftl->col1 = 0xFF0000;
	ftl->col2 = 0x00FFFF;
	return (ftl);
}
