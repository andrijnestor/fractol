/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anestor <anestor@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:05:01 by anestor           #+#    #+#             */
/*   Updated: 2018/01/31 13:36:50 by anestor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

#define THREADS 8
#define MAX_ITER 50000

void	*test_function(void *arg)
{
	int		i;
	int		j;

	i = 0;
	while (i != MAX_ITER)
	{
		j = 0;
		while (j != MAX_ITER)
		{			
			j++;
		}
		i++;
	}
	printf("test\n");
	pthread_exit(0);
//	return (0);
}

int		main(void)
{
	int			i;
	pthread_t	tid[THREADS];

	i = 0;
	while (i != THREADS)
	{
//		test_function(0);
		pthread_create(&tid[i], NULL, test_function, NULL);
		printf("space\n");
		i++;
	}
//	pthread_join(tid[i], NULL);
	
	i = 0;
	while (i != THREADS)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	
	return (0);
}
