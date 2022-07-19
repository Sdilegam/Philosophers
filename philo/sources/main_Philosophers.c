/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   main_philosophers.c                              +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/19 12:28:24 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/19 18:26:58 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#include "Philosophers.h"
#include "main_Philosophers.h"

void	*routine(void *bridge)
{
	t_philo	*philo;

	philo = bridge;
	struct timeval tp;
	gettimeofday(&tp, 0);
	pthread_mutex_lock(&(philo->forks[0]));
	pthread_mutex_lock(&(philo->forks[1]));
	pthread_mutex_lock(&philo->params->print);
	printf("%d, %ld mange\n", tp.tv_usec, tp.tv_sec);
	printf("Fini\n");
	pthread_mutex_unlock(&philo->params->print);
	pthread_mutex_unlock(&(philo->forks[1]));
	pthread_mutex_unlock(&(philo->forks[0]));
	return (0);
}

t_philo	*initiate_philosophers(t_g_params *params)
{
	t_philo	*philosophers_list;
	t_philo	*cursor;
	int		index;

	index = 0;
	philosophers_list = create_node(params);
	cursor = philosophers_list;
	cursor->id = ++index;
	pthread_mutex_init(&cursor->forks[0], 0);
	pthread_mutex_init(&cursor->forks[1], 0);
	while (++index < params->total_philos)
	{
		join_node(cursor, create_node(params));
		cursor = cursor->next;
		cursor->id = index;
		cursor->forks[0] = cursor->previous->forks[1];
		pthread_mutex_init(&cursor->forks[1], 0);
	}
	join_node(cursor, create_node(params));
	cursor = cursor->next;
	cursor->id = index;
	cursor->forks[0] = cursor->previous->forks[1];
	cursor->forks[1] = philosophers_list->forks[0];
	return (philosophers_list);
}

t_g_params	initiate_parameters(int argc, char **argv)
{
	t_g_params	base_parameters;

	base_parameters.total_philos = ft_atoi(argv[1]);
	base_parameters.time_death = ft_atoi(argv[2]);
	base_parameters.time_eat = ft_atoi(argv[3]);
	base_parameters.time_sleep = ft_atoi(argv[4]);
	base_parameters.total_eat = -1;
	if (argc == 6)
		base_parameters.total_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&base_parameters.print, 0);
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
		cursor = cursor->next;
	}
	pthread_join(threads[base_parameters.total_philos - 1], 0);
	return (0);
}
