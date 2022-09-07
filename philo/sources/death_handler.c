/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:12:05 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/07 09:35:15 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "death_handler.h"

void	check_death(t_philo *philo, unsigned long start)
{
	struct timeval	end;
	t_philo			*cursor;

	cursor = philo;
	while (1)
	{
		gettimeofday(&end, 0);
		pthread_mutex_lock(&philo->params->dying);
		if (philo->params->finished == philo->params->total_philos)
		{
			philo->params->end = 1;
			pthread_mutex_unlock(&philo->params->dying);
			return ;
		}
		else if ((int)(convert_time(end)
					- cursor->last_ate) >= cursor->params->time_death)
		{
			philo->params->end = 1;
			pthread_mutex_lock(&philo->params->print);
			printf("%lu\t\t%d died\n", convert_time(end) - start, cursor->id);
			pthread_mutex_unlock(&philo->params->print);
			pthread_mutex_unlock(&philo->params->dying);
			return ;
		}
		else
			pthread_mutex_unlock(&philo->params->dying);
		cursor = cursor->next;
	}
	cursor = cursor->next;
}
