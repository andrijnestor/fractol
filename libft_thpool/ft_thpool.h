/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thpool.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:29:49 by anestor           #+#    #+#             */
/*   Updated: 2018/02/04 18:12:57 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_THPOOL_H
# define FT_THPOOL_H
# include <pthread.h>
# include <stdlib.h>

typedef struct		s_tp_thread
{
	pthread_t		*tid;
	int				threads;
	pthread_mutex_t	mutex;
	pthread_cond_t	cv;
	int				wait;
}					t_tp_thread;

t_tp_thread			*tp_create(int threads);
int					tp_exec_queue_add(t_tp_thread *tp,
						void *(*start_routine)(void *) , void *restrict arg);
void				tp_wait_for_queue(t_tp_thread *tp);
void				tp_wait_for_signal(t_tp_thread *tp);
void				tp_signal(t_tp_thread *tp);

#endif
