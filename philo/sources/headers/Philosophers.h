/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   Philosophers.h                                   +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/18 13:00:13 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/20 16:56:27 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <sys/time.h>

typedef pthread_mutex_t	t_mutex;


typedef struct s_g_params{
	int	total_philos;
	int	time_death;
	int time_eat;
	int	time_sleep;
	int	total_eat;
	unsigned long start_time;
	pthread_mutex_t	print;
}	t_g_params;

typedef struct s_philo{
	int				id;
	struct s_philo	*next;
	struct s_philo	*previous;
	pthread_mutex_t	forks[2];
	t_g_params		*params;
}	t_philo;


#endif /* TYPE_DEFINITION_H */
