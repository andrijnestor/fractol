/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:43:23 by anestor           #+#    #+#             */
/*   Updated: 2018/01/30 23:39:51 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_xpm(t_ftl *ftl)
{
	int		i;
	char	*tmp;

	ftl->xpm = (char **)malloc(sizeof(char *) * (COLOR_N + WIN_H + 2));
	i = 0;
	ftl->xpm[i++] = ft_strdup("1000 1000 100 2");
	while (i != COLOR_N + 1)
	{
		tmp = ft_itoa(i - 1);
		if (ft_strlen(tmp) > 1)
			ftl->xpm[i] = ft_strjoin(tmp, " c #000044");
		else
			ftl->xpm[i] = ft_strjoin(tmp, "  c #000044");
		free(tmp);
		i++;
	}
	while (i != (COLOR_N + WIN_H + 2))
	{
		ftl->xpm[i] = ft_strnew(WIN_W * 3);
		ft_memset(ftl->xpm[i], ' ', WIN_W * 2); // delete
		i++;
	}
	ftl->xpm[i] = NULL;
}
