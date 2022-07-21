/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   main_Philosophers.c                              +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/19 12:28:24 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/21 17:55:41 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

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
		usleep((100));
	while (1)
	{
		routine_take_fork(philo, 0, start);
		routine_take_fork(philo, 1, start);
		routine_eat(philo, start, &finished, ++index);
		routine_sleep(philo, start);
		routine_think(philo, start);
	}
	return (0);
}

t_philo	*initiate_philosophers(t_g_params *params)
{
	t_philo	*philosophers_list;
	t_philo	*cursor;
	int		index;

	index = 1;
	philosophers_list = create_node(params);
	cursor = philosophers_list;
	cursor->next = cursor;
	cursor->id = index;
	cursor->lfork = malloc(sizeof(pthread_mutex_t));
	cursor->rfork = 0;
	if (pthread_mutex_init(cursor->lfork, 0) != 0)
		printf(("aled\n"));
	cursor->last_ate = params->start_time;
	while (++index < params->total_philos)
	{
		join_node(cursor, create_node(params));
		cursor = cursor->next;
		cursor->id = index;
		cursor->lfork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(cursor->lfork, 0) != 0)
			printf(("aled\n"));
		cursor->previous->rfork = cursor->lfork;
		cursor->last_ate = params->start_time;
	}
	if (params->total_philos > 1)
	{
		join_node(cursor, create_node(params));
		cursor = cursor->next;
		cursor->next = philosophers_list;
		cursor->id = index;
		cursor->lfork = malloc(sizeof(pthread_mutex_t));
		if (pthread_mutex_init(cursor->lfork, 0) != 0)
			printf(("aled\n"));
		cursor->previous->rfork = cursor->lfork;
		cursor->rfork = philosophers_list->lfork;
		cursor->last_ate = params->start_time;
	}
	return (philosophers_list);
}

t_g_params	initiate_parameters(int argc, char **argv)
{
	struct timeval	temp;
	t_g_params		base_parameters;

	gettimeofday(&temp, 0);
	base_parameters.start_time = convert_time(temp);
	base_parameters.total_philos = ft_atoi(argv[1]);
	base_parameters.time_death = ft_atoi(argv[2]);
	base_parameters.time_eat = ft_atoi(argv[3]);
	base_parameters.time_sleep = ft_atoi(argv[4]);
	base_parameters.total_eat = -1;
	if (argc == 6)
		base_parameters.total_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&base_parameters.print, 0);
	pthread_mutex_init(&base_parameters.death, 0);
	base_parameters.finished = 0;
	return (base_parameters);
}

int	main(int argc, char **argv)
{
	t_g_params	base_parameters;
	t_philo		*philo;
	t_philo		*cursor;
	pthread_t	*threads;
	int			index;

	if (argc < 5 || 6 < argc)
		return (0);
	index = -1;
	base_parameters = initiate_parameters(argc, argv);
	threads = malloc(sizeof(pthread_t) * base_parameters.total_philos);
	philo = initiate_philosophers((&base_parameters));
	cursor = philo;
	while (++index < base_parameters.total_philos)
	{
		pthread_create(&threads[index], 0, &routine, cursor);
		pthread_detach(threads[index]);
		cursor = cursor->next;
	}
	check_death(philo, base_parameters.start_time);
	return (0);
}
