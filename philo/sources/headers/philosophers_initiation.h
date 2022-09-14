/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_initiation.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:01:36 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 12:01:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_INITIATION_H
# define PHILOSOPHERS_INITIATION_H

int		allocate_init_mutexes(t_philo *ph, t_philo *cursor, pthread_t *th,
			int i);
void	clean_all(t_philo *philos, pthread_t *threads, int len,
			t_params *params);
t_philo	*initiate_philosophers(t_params *params, pthread_t *threads);
t_philo	*add_node(t_philo *last);
t_philo	*create_node(t_params *params);
t_philo	*add_philo(t_params *params, t_philo **first, int i, t_philo *cursor);

#endif
