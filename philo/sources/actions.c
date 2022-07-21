/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   actions.c                                        +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/21 11:27:04 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/21 13:38:05 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#include "Philosophers.h"
#include "actions.h"

void	routine_take_fork(t_philo *philo, int fork, unsigned long start)
{
	struct timeval	end;

	pthread_mutex_lock(&(philo->forks[fork]));
	gettimeofday(&end, 0);
	if ((int)(convert_time(end) - philo->last_ate) >= philo->params->time_death)
	{
		pthread_mutex_lock(&philo->params->death);
		philo->params->finished = 1;
		pthread_mutex_lock(&philo->params->print);
		printf("◦%lu %d is dead\n", convert_time(end) - start, philo->id);
		pthread_mutex_unlock(&philo->params->print);
		pthread_mutex_unlock(&(philo->forks[fork]));
		exit(1);
		pthread_mutex_unlock(&philo->params->death);
	}
	pthread_mutex_lock(&philo->params->print);
	printf("◦%lu %d has taken a fork\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
}

void	routine_eat(t_philo *philo, unsigned long start)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	if ((int)(convert_time(end) - philo->last_ate) > philo->params->time_death)
	{
		pthread_mutex_lock(&philo->params->death);
		philo->params->finished = 1;
		pthread_mutex_lock(&philo->params->print);
		printf("◦%lu %d is dead\n", convert_time(end) - start, philo->id);
		pthread_mutex_unlock(&philo->params->print);
		exit(1);
		pthread_mutex_unlock(&philo->params->death);
	}
	wait_mili(end, philo->params->time_eat);
	pthread_mutex_lock(&philo->params->print);
	printf("◦%lu %d is eating\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
	philo->last_ate = convert_time(end);
	// pthread_mutex_unlock(&(philo->forks[0]));
	pthread_mutex_unlock(&(philo->forks[0]));
	pthread_mutex_unlock(&(philo->forks[1]));
}

void	routine_sleep(t_philo *philo, unsigned long start)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	if ((int)(convert_time(end) - philo->last_ate) >= philo->params->time_death)
	{
		pthread_mutex_lock(&philo->params->death);
		philo->params->finished = 1;
		pthread_mutex_lock(&philo->params->print);
		printf("◦%lu %d is dead\n", convert_time(end) - start, philo->id);
		pthread_mutex_unlock(&philo->params->print);
		exit(1);
		pthread_mutex_unlock(&philo->params->death);
	}
	wait_mili(end, philo->params->time_sleep);
	pthread_mutex_lock(&philo->params->print);
	printf("◦%lu %d is sleeping\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
}

void	routine_think(t_philo *philo, unsigned long start)
{
	struct timeval	end;

	gettimeofday(&end, 0);
	if ((int)(convert_time(end) - philo->last_ate) >= philo->params->time_death)
	{
		pthread_mutex_lock(&philo->params->death);
		philo->params->finished = 1;
		pthread_mutex_lock(&philo->params->print);
		printf("◦%lu %d died\n", convert_time(end) - start, philo->id);
		pthread_mutex_unlock(&philo->params->print);
		exit(1);
		pthread_mutex_unlock(&philo->params->death);
	}
	pthread_mutex_lock(&philo->params->print);
	printf("◦%lu %d is thinking\n", convert_time(end) - start, philo->id);
	pthread_mutex_unlock(&philo->params->print);
}
