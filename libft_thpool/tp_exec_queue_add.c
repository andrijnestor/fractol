/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_exec_queue_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:11:57 by anestor           #+#    #+#             */
/*   Updated: 2018/02/04 18:12:29 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_thpool.h"

int		tp_exec_queue_add(t_tp_thread *tp, void *(*start_routine)(void *), void *restrict arg)
{
	int		i;

	i = 0;
	while (i != tp->threads)
	{
		pthread_create(&tp->tid[i], NULL, start_routine, arg);
		i++;
		if (tp->wait == 1)
		{
			pthread_cond_wait(&tp->cv, &tp->mutex);
		}
	}
	return (0);
}
