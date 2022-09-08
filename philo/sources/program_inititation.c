/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_inititation.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:48:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 10:42:19 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "program_inititation.h"

int	check_params(t_params *p)
{
	if (p->n_philos < 1 || p->time_death < 1 || p->time_eat < 1
		|| p->time_sleep < 1 || p->total_eat == -10)
	{
		printf("Bad parameters.\nPlease use parameters bigger than 0.\n");
		return (1);
	}
	if (set_global_mutexes(p) == 1)
		return (1);
	return (0);
}

void	create_threads(pthread_t *threads, t_philo *philosopher, int n_philos)
{
	t_philo	*cursor;
	int		index;

	index = -1;
	cursor = philosopher;
	while (++index < n_philos && cursor)
	{
		pthread_create(&threads[index], 0, &routine, cursor);
		cursor = cursor->next;
	}
}

void	join_threads(pthread_t *threads, int n_philos)
{
	int	index;

	index = -1;
	while (++index < n_philos)
		pthread_join(threads[index], 0);
}

t_params	initiate_parameters(int argc, char **argv)
{
	struct timeval	temp;
	t_params		base_parameters;

	gettimeofday(&temp, 0);
	base_parameters.finished = 0;
	base_parameters.end = 0;
	base_parameters.start_time = convert_time(temp);
	base_parameters.n_philos = ft_atoi(argv[1]);
	base_parameters.time_death = ft_atoi(argv[2]);
	base_parameters.time_eat = ft_atoi(argv[3]);
	base_parameters.time_sleep = ft_atoi(argv[4]);
	base_parameters.total_eat = -100;
	if (argc == 6)
		base_parameters.total_eat = ft_atoi(argv[5]);
	return (base_parameters);
}

int	set_global_mutexes(t_params *params)
{
	if (pthread_mutex_init(&params->print, 0) != 0)
		return (1);
	if (pthread_mutex_init(&params->dying, 0) != 0)
	{
		pthread_mutex_destroy(&params->print);
		return (1);
	}
	return (0);
}
