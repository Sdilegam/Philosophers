/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 11:27:04 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/07 10:01:00 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "actions.h"

int	routine_take_fork(t_philo *philo, int fork, unsigned long start)
{
	struct timeval	end;

	if (fork == 0)
		pthread_mutex_lock(philo->lfork);
	else
	{
		if (philo->rfork != philo->lfork)
			pthread_mutex_lock(philo->rfork);
		else
			usleep((philo->params->time_death + 1) * 1000);
	}
	gettimeofday(&end, 0);
	pthread_mutex_lock(&philo->params->dying);
	if (philo->params->end == 1)
	{
		pthread_mutex_unlock(philo->lfork);
		if (fork == 1)
			pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(&philo->params->dying);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->dying);
	pthread_mutex_lock(&philo->params->print);
	printf("%lu\t\t%d has taken a fork\n", convert_time(end) - start,
			philo->id);
	pthread_mutex_unlock(&philo->params->print);
	return (0);
}

int	routine_eat(t_philo *philo, unsigned long start, int *finished, int i)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	pthread_mutex_lock(&philo->params->dying);
	philo->last_ate = convert_time(end);
	if (philo->params->end == 1)
	{
		pthread_mutex_unlock(&philo->params->dying);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->dying);
	pthread_mutex_lock(&philo->params->print);
	printf("%lu\t\t%d is eating\n", convert_time(end) - start, philo->id);
	if (i == philo->params->total_eat && !*finished)
		philo->params->finished += ++*(finished);
	pthread_mutex_unlock(&philo->params->print);
	wait_mili(end, philo->params->time_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
	return (0);
}

int	routine_sleep(t_philo *philo, unsigned long start)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	pthread_mutex_lock(&philo->params->dying);
	if (philo->params->end == 1)
	{
		pthread_mutex_unlock(&philo->params->dying);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->dying);
	pthread_mutex_lock(&philo->params->print);
	printf("%lu\t\t%d is sleeping\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
	wait_mili(end, philo->params->time_sleep);
	return (0);
}

int	routine_think(t_philo *philo, unsigned long start)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	pthread_mutex_lock(&philo->params->dying);
	if (philo->params->end == 1)
	{
		pthread_mutex_unlock(&philo->params->dying);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->dying);
	pthread_mutex_lock(&philo->params->print);
	printf("%lu\t\t%d is thinking\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
	return (0);
}
