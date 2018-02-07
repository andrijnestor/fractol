/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:27:29 by anestor           #+#    #+#             */
/*   Updated: 2018/02/07 16:50:17 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hooks(int keycode, t_ftl *ftl)
{
	if (keycode == 124)
		ftl->move_x += 0.1 / ftl->zoom;
	if (keycode == 123)
		ftl->move_x -= 0.1 / ftl->zoom;
	if (keycode == 126)
		ftl->move_y -= 0.1 / ftl->zoom;
	if (keycode == 125)
		ftl->move_y += 0.1 / ftl->zoom;
	if (keycode == 69 || keycode == 24)
		ftl->zoom *= 1.1;
	if (keycode == 18)
		if (ftl->max_iter > 0)
			ftl->max_iter -= 10;
	if (keycode == 19)
		ftl->max_iter += 10;
	if (keycode == 20)
		if (ftl->col_depth > 0)
			ftl->col_depth -= 1;
	if (keycode == 21)
		ftl->col_depth += 1;
	if (keycode == 23)
		ftl->col1 = (int)(ftl->col1 * 1.1) % 0xFFFFFF;
	if (keycode == 22)	
		ftl->col2 = (int)(ftl->col2 * 1.1) % 0xFFFFFF;
	if (keycode == 78 || keycode == 27)
		ftl->zoom /= 1.1;
	if (keycode == 48)
		ftl->type = (ftl->type + 1) % 2;
	if (keycode == 53)
		exit(0);
	fractol_put(ftl);
	return (0);
}

int		exit_on_x(void *tmp)
{
	(void)tmp;
	exit(1);
	return (0);
}
