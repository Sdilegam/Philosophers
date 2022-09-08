/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_initiation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:08:51 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 10:42:19 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"
#include "philosophers_initiation.h"

t_philo	*add_philo(t_params *params, t_philo **first, int i, t_philo *cursor)
{
	if (i == 0)
	{
		*first = create_node(params);
		return (*first);
	}
	else
		return (add_node(cursor));
}

t_philo	*initiate_philosophers(t_params *params, pthread_t *threads)
{
	t_philo	*first;
	t_philo	*cursor;
	int		index;

	index = -1;
	while (++index < params->n_philos)
	{
		cursor = add_philo(params, &first, index, cursor);
		if (!cursor)
		{
			clean_all(first, threads, index, params);
			return (0);
		}
		if (allocate_init_mutexes(first, cursor, threads, index))
			return (0);
		cursor->previous->rfork = cursor->lfork;
		if (index == params->n_philos - 1)
		{
			cursor->next = first;
			cursor->rfork = first->lfork;
		}
	}
	return (first);
}

int	allocate_init_mutexes(t_philo *ph, t_philo *cursor, pthread_t *th, int i)
{
	cursor->lfork = malloc(sizeof(t_mutex));
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
