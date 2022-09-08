/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:28:24 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 09:35:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "main_Philosophers.h"

void	*routine(void *bridge)
{
	t_philo			*philo;
	unsigned long	start;
	int				index;
	int				finished;

	index = 0;
	philo = bridge;
	finished = 0;
	start = philo->params->start_time;
	if (philo->id % 2 == 0)
		usleep((1000));
	while (1)
	{
		if (routine_take_fork(philo, 0, start) == 1 || routine_take_fork(philo,
				1, start) == 1 || routine_eat(philo, start, &finished,
				++index) == 1 || routine_sleep(philo, start) == 1
			|| routine_think(philo, start) == 1)
			return (0);
	}
	return (0);
}

int	check_params(t_g_params *p)
{
	if (p->total_philos < 1 || p->time_death < 1 || p->time_eat < 1
		|| p->time_sleep < 1 || p->total_eat == -10)
	{
		printf("Bad parameters.\nPlease use parameters bigger than 0.\n");
		return (1);
	}
	if (set_global_mutexes(p) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_g_params	base_parameters;
	t_philo		*philo;
	t_philo		*cursor;
	pthread_t	*threads;
	int			index;

	index = -1;
	if (argc < 5 || 6 < argc)
		return (1);
	base_parameters = initiate_parameters(argc, argv);
	if (check_params(&base_parameters) == 1)
		return (1);
	threads = malloc(sizeof(pthread_t) * base_parameters.total_philos);
	if (threads == 0)
		return (1);
	philo = initiate_philosophers((&base_parameters), threads);
	if (!philo)
		return (1);
	cursor = philo;
	while (++index < base_parameters.total_philos && cursor)
	{
		pthread_create(&threads[index], 0, &routine, cursor);
		cursor = cursor->next;
	}
	check_death(philo, base_parameters.start_time);
	while (index > -1)
		pthread_join(threads[index--], 0);
	clean_exit(philo, threads, philo->params->total_philos, &base_parameters);
	return (0);
}
