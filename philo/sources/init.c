/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 08:48:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 10:07:16 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "init.h"

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

int	allocate_init_mutexes(t_philo *ph, t_philo *cursor, pthread_t *th, int i)
{
	cursor->lfork = malloc(sizeof(pthread_mutex_t));
	if (!cursor->lfork)
	{
		clean_all(ph, th, i + 1, ph->params);
		return (1);
	}
	else if (pthread_mutex_init(cursor->lfork, 0) != 0)
	{
		free(cursor->lfork);
		cursor->lfork = 0;
		clean_all(ph, th, i + 1, ph->params);
		return (1);
	}
	return (0);
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
		if (!cursor)
		{
			clean_all(philosophers_list, threads, index, params);
			return (0);
		}
		if (allocate_init_mutexes(philosophers_list, cursor, threads, index))
			return (0);
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
