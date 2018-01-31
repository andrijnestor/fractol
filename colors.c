/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 17:31:46 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 01:02:50 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_ito_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
/*

char	*ft_ito_base(int number, int base) //hz sho blia
{
	int		numb;
	int		len;
	char	*numbase;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_num_len(number) - 2;
	numb = ((number < 0) ? (number * -1) : (number));
	if ((numbase = ft_strnew(len)) == NULL)
		return (NULL);
	while (len-- != -1)
	{
		numbase[len] = numb % base + ((numb % base > 9) ? ('7') : ('0'));
		numb = numb / base;
	}
	if (number < 0)
		numbase[0] = '-';
	return (numbase);
}

*/
static int	color_grad(int start, int end, double perc)
{
	if (start == end)
		return (start);
	return ((int)((double)start + (end - start) * perc));
}

int	rgb_grad(int c1, int c2, double perc)
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

static void	color_range(int col1, int col2, t_ftl *ftl)
{
	int		i;
	char	*tmp;

//	tmp = ft_strnew(6);
	i = 1;
	while (i != COLOR_N + 1)
	{
		tmp = ft_ito_base(rgb_grad(col1, col2, i / 100.0), 16);
	//	tmp = "ffffff";
	//	(void)col1;
	//	(void)col2;
//		printf("%s %f\n", tmp, i / 100.0);	
//		sprintf(tmp, "%x", rgb_grad(col1, col2, i / 100.0));
		ft_memcpy(&ftl->xpm[i][6], tmp, 6);
		free(tmp);
		i++;
	}
//	free(tmp);
}

void		color_range_init(t_ftl *ftl)
{
	color_range(0xFF0000, 0xFFFF00, ftl);
}
