/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:08:29 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 22:02:45 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_xpm(t_ftl *ftl)
{
	int		i;
	char	*tmp;

	ftl->xpm = (char **)malloc(sizeof(char *) * (COLOR_N + WIN_H + 2));
	i = 0;
	ftl->xpm[i++] = ft_strdup("800 600 256 2");
	while (i != COLOR_N + 1)
	{
		tmp = ft_itoa_base_int(i - 1, 16);
		if (ft_strlen(tmp) > 1)
			ftl->xpm[i] = ft_strjoin(tmp, " c #000000");
		else
			ftl->xpm[i] = ft_strjoin(tmp, "  c #000000");
		free(tmp);
		i++;
	}
	while (i != (COLOR_N + WIN_H + 2))
	{
		ftl->xpm[i] = ft_strnew(WIN_W * 2);
		ft_memset(ftl->xpm[i], ' ', WIN_W * 2);
		i++;
	}
	ftl->xpm[i] = NULL;
}

void	put_image(t_ftl *ftl)
{
	ftl->img = mlx_xpm_to_image(ftl->mlx, ftl->xpm, &ftl->winW,  &ftl->winH);
	mlx_put_image_to_window(ftl->mlx, ftl->win, ftl->img, 0, 0);
}

void	xpm_pixel_put(t_ftl *ftl, int x, int y, int col)
{
	char	*tmp;

	ft_memcpy(&ftl->xpm[y + COLOR_N + 1][x * 2], "  ", 2);
	if (col < ftl->maxIter)
	{
		col = (col * ftl->colDepth * col / COLOR_N) % COLOR_N;
		tmp = ft_itoa_base_int(col, 16);
		ft_memcpy(&ftl->xpm[y + COLOR_N + 1][x * 2], tmp, ft_strlen(tmp));
		free(tmp);
	}
}
