/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:40:15 by anestor           #+#    #+#             */
/*   Updated: 2018/02/04 18:05:09 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_thpool.h"

t_tp_thread	*tp_create(int threads)
{
	t_tp_thread	*tp;

	if ((tp = (t_tp_thread *)malloc(sizeof(t_tp_thread))) == NULL)
		return (NULL);
	tp->threads = 0;
	tp->wait = 0;
	if ((tp->tid = malloc(sizeof(pthread_t) * threads)) == NULL)
		return (NULL);
	return (tp);
}
