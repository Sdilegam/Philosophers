/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   death_handler.c                                  +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/21 16:12:05 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/21 17:24:18 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#include "Philosophers.h"
#include "death_handler.h"

void	check_death(t_philo *philo, unsigned long start)
{
	struct timeval	end;
	t_philo			*cursor;

	cursor = philo;
	while (1)
	{
		if (philo->params->finished == philo->params->total_philos)
			exit(0);
		gettimeofday(&end, 0);
		if ((int)(convert_time(end)
				- cursor->last_ate) >= cursor->params->time_death)
		{
			pthread_mutex_lock(&philo->params->print);
			printf("%lu\t\t%d died\n", convert_time(end) - start, cursor->id);
			// system("leaks philo");
			exit(1);
		}
		cursor = cursor->next;
	}
	cursor = cursor->next;
}
