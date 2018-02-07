/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 20:10:02 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 16:38:00 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mouse_down(int button, int x, int y, t_ftl *ftl)
{
	(void)x;
	(void)y;

	if (button == 4)
	{
		ftl->move_y -= (y) / (double)WIN_H * 1.5;
		ftl->move_x -= (x) / (double)WIN_W * 1.5;
		ftl->zoom *= 1.2;
	}
	else if (button == 5)
	{
		ftl->move_y -= (y) / (double)WIN_H * 1.5;
		ftl->move_x -= (x) / (double)WIN_W * 1.5;
		ftl->zoom /= 1.2;
	}
	ftl->mouse.is_down = button;
	fractol_put(ftl);
	return (0);
}

int		hook_mouse_up(int button, int x, int y, t_ftl *ftl)
{
	(void)x;
	(void)y;
	(void)button;
	ftl->mouse.is_down = 0;
	return (0);
}

int		hook_mouse_move(int x, int y, t_ftl *ftl)
{
	ftl->mouse.last_x = ftl->mouse.x;
	ftl->mouse.last_y = ftl->mouse.y;
	ftl->mouse.x = x;
	ftl->mouse.y = y;
	if (ftl->mouse.is_down == 1)
	{
		ftl->move_y += (ftl->mouse.last_y - y) / (double)WIN_H * 2;
		ftl->move_x += (ftl->mouse.last_x - x) / (double)WIN_W * 3;
	}
	else if (ftl->mouse.is_down == 2)
	{
//		ftl->x_angle -= (ftl->mouse.last_y - y) / 2;
//		ftl->z_angle += (ftl->mouse.last_x - x) / 2;
	}
//	else if (ftl->mouse.is_down == 4)
//		ftl->zoom *= 1.1;
//	else if (ftl->mouse.is_down == 5)
//		ftl->zoom /= 1.1;
	if (ftl->mouse.is_down)
	{
//		mlx_clear_window(fdf->mlx, fdf->win);
//		render(fdf);
	}
	printf("x: %d y: %d\n", ftl->mouse.x, ftl->mouse.y);
	fractol_put(ftl);
	return (0);
}
