/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:08:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/29 11:21:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "clean_exit.h"

void	clean_philos(t_philo *philos, int length)
{
	int		index;
	t_philo	*temp;
	t_philo	*cursor;

	index = 0;
	cursor = philos;
	while (++index <= length)
	{
		if (cursor->lfork)
		{
			if (cursor->lfork->__sig != 0)
				pthread_mutex_destroy(cursor->lfork);
			free(cursor->lfork);
		}
		temp = cursor->next;
		free(cursor);
		cursor = temp;
	}
}

void	clean_params(t_g_params *params)
{
	pthread_mutex_destroy(&params->dying);
	pthread_mutex_destroy(&params->print);
}

void	clean_all(t_philo *philos, pthread_t *threads, int len)
{
	free(threads);
	clean_params(philos->params);
	clean_philos(philos, len);
}

void	clean_exit(t_philo *philos, pthread_t *threads, int len)
{
	clean_all(philos, threads, len);
}
