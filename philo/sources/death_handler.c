/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:12:05 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/29 11:32:19 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "death_handler.h"

void	check_death(t_philo *philo, unsigned long start, pthread_t *threads)
{
	struct timeval	end;
	t_philo			*cursor;

	cursor = philo;
	while (1)
	{
		if (philo->params->finished == philo->params->total_philos)
		{
			clean_exit(philo, threads, philo->params->total_philos);
		}
		gettimeofday(&end, 0);
		if ((int)(convert_time(end)
				- cursor->last_ate) >= cursor->params->time_death)
		{
			pthread_mutex_lock(&philo->params->dying);
			philo->params->end = 1;
			pthread_mutex_lock(&philo->params->print);
			printf("%lu\t\t%d died\n", convert_time(end) - start, cursor->id);
			pthread_mutex_unlock(&philo->params->print);
			pthread_mutex_unlock(&philo->params->dying);
			return ;
		}
		cursor = cursor->next;
	}
	cursor = cursor->next;
}
