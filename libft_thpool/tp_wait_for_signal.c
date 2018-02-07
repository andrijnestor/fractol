/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tp_wait_for_signal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:58:25 by anestor           #+#    #+#             */
/*   Updated: 2018/02/04 18:00:04 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_thpool.h"

void	tp_wait_for_signal(t_tp_thread *tp)
{
	pthread_mutex_init(&tp->mutex, NULL);
	pthread_cond_init(&tp->cv, NULL);
	tp->wait = 1;
}
