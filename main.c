/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:14:00 by anestor           #+#    #+#             */
/*   Updated: 2018/02/09 01:01:04 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	pid_t	pid;
	int		ret;

	pid = getpid();
	if (argc < 2 || argc > 3)
		return (ftl_usage());
	else
	{
		if (argc == 3)
			fork();
		if (getpid() == pid && argc == 3)
			ret = fractol_make(argv[2]);
		else
			ret = fractol_make(argv[1]);
		if (ret == 1)
			return(ftl_usage());
		else if (ret == 2)
		{
			write(1, "Mem allocation error\n", 21);
			return (1);
		}
	}
	return (0);
}

int		fractol_make(char *name)
{
	t_ftl	*ftl;
	int		type;

	if (!ft_strcmp(name, "mandelbrot") || !ft_strcmp(name, "-m"))
		type = 0;
	else if (!ft_strcmp(name, "julia") || !ft_strcmp(name, "-j"))
		type = 1;
	else if (!ft_strcmp(name, "burning_ship") || !ft_strcmp(name, "-s"))
		type = 2;
	else
		return (1);
	if ((ftl = ftl_init(type, name)) == NULL)
		return (2);
	create_img(ftl);
	put_fractol(ftl);
	put_img(ftl);
	mlx_hook(ftl->win, 2, 5, key_hooks, ftl);
	mlx_hook(ftl->win, 4, 0, hook_mouse_down, ftl);
	mlx_hook(ftl->win, 5, 0, hook_mouse_up, ftl);
	mlx_hook(ftl->win, 6, 0, hook_mouse_move, ftl);
	mlx_hook(ftl->win, 17, 1L << 17, exit_on_x, NULL);
	mlx_loop(ftl->mlx);
	return (0);
}

t_ftl	*ftl_init(int type, char *name)
{
	t_ftl	*ftl;

	if ((ftl = malloc(sizeof(t_ftl))) == NULL)
		return (NULL);
	ftl->type = type;
	ftl->mlx = mlx_init();
	ftl->win_h = WIN_H;
	ftl->win_w = WIN_W;
	ftl->win = mlx_new_window(ftl->mlx, ftl->win_w, ftl->win_h, name);
	ftl->zoom = 1;
	if (type == 0)
		ftl->move_x = -0.5;
	else if (type == 2)
		ftl->move_x = -0.5;
	else
		ftl->move_x = 0;
	if (type == 2)
		ftl->move_y = -0.5;
	else
		ftl->move_y = 0;
	ftl->max_iter = 50;
	ftl->col_depth = 1;
	ftl->col1 = 0xFF0000;
	ftl->col2 = 0x00FFFF;
	return (ftl);
}

int		ftl_usage(void)
{
	write(1, "Usage:\n./fractol [type]\ntype 1: -m or mandelbrot\n", 49);
	write(1, "type 2: -j or julia\ntype 3: -s or burning_ship\n", 47);
	write(1, "./fractol [type] [type] - for double window\n\n", 45);
	write(1, "UP, DOWN, LEFT, RIGTH - for moving\n", 35);
	write(1, "or mouse left button + move mouse - for moving\n", 47);
	write(1, "PLUS and MINUS - for zoom\n", 26);
	write(1, "or mouse scroll - for zoom\n\n", 28);
	write(1, "1 and 2 - for decrease and increase max iterations\n", 51);
	write(1, "3 and 4 - for decrease and increase col depth\n", 46);
	write(1, "5 and 6 - for random colors\n", 28);
	write(1, "TAB - for switching fractols\n", 29);
	return (1);
}
