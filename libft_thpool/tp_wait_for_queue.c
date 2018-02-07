/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_wait_for_queue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:56:13 by anestor           #+#    #+#             */
/*   Updated: 2018/02/04 18:12:51 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_thpool.h"

void	tp_wait_for_queue(t_tp_thread *tp)
{
	int		i;

	i = 0;
	while (i != tp->threads)
	{
		pthread_join(tp->tid[i], NULL);
		i++;
	}
}
