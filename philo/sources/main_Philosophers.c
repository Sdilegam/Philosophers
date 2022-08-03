/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_Philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:28:24 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/08/03 17:07:11 by sdi-lega         ###   ########.fr       */
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

void	allocate_init_mutexes(t_philo *ph, t_philo *cursor, pthread_t *th,
		int i)
{
	cursor->lfork = malloc(sizeof(pthread_mutex_t));
	if (!cursor->lfork)
		clean_exit(ph, th, i + 1);
	if (pthread_mutex_init(cursor->lfork, 0) != 0)
		clean_exit(ph, th, i + 1);
}

t_philo	*initiate_philosophers(t_g_params *params, pthread_t *threads)
{
	t_philo	*philosophers_list;
	t_philo	*cursor;
	int		index;

	index = -1;
	while (++index < params->total_philos)
	{
		if (index == 0)
		{
			philosophers_list = create_node(params);
			cursor = philosophers_list;
		}
		else
			cursor = join_node(cursor, create_node(params));
		allocate_init_mutexes(philosophers_list, cursor, threads, index);
		cursor->previous->rfork = cursor->lfork;
		if (index == params->total_philos - 1)
		{
			cursor->next = philosophers_list;
			cursor->rfork = philosophers_list->lfork;
		}
	}
	return (philosophers_list);
}

int	set_global_mutexes(t_g_params *params)
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

int	check_params(t_g_params *p)
{
	if (p->total_philos == -1 || p->time_death == -1 || p->time_eat == -1 || p->time_sleep == -1 || p->total_eat == -10)
	{
		printf("Bad parameters\n");
		return (1);
	}
	if (set_global_mutexes(p) == 1)
		return (1);
	return (0);
}


t_g_params	initiate_parameters(int argc, char **argv)
{
	struct timeval	temp;
	t_g_params		base_parameters;

	gettimeofday(&temp, 0);
	base_parameters.finished = 0;
	base_parameters.end = 0;
	base_parameters.start_time = convert_time(temp);
	base_parameters.total_philos = ft_atoi(argv[1]);
	base_parameters.time_death = ft_atoi(argv[2]);
	base_parameters.time_eat = ft_atoi(argv[3]);
	base_parameters.time_sleep = ft_atoi(argv[4]);
	base_parameters.total_eat = -100;
	if (argc == 6)
		base_parameters.total_eat = ft_atoi(argv[5]);
	return (base_parameters);
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
	cursor = philo;
	while (++index < base_parameters.total_philos)
	{
		pthread_create(&threads[index], 0, &routine, cursor);
		cursor = cursor->next;
	}
	check_death(philo, base_parameters.start_time, threads);
	index = -1;
	while (++index < base_parameters.total_philos)
		pthread_join(threads[index], 0);
	clean_exit(philo, threads, philo->params->total_philos);
	return (0);
}
