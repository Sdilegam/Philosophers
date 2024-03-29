/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:52:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 11:53:36 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

int				routine_think(t_philo *philo, unsigned long start);
int				routine_sleep(t_philo *philo, unsigned long start);
void			wait_mili(struct timeval start, long double duration);
int				routine_eat(t_philo *philo, unsigned long start, int *finished,
					int i);
unsigned long	convert_time(struct timeval time);
int				routine_take_fork(t_philo *philo, int fork,
					unsigned long start);
void			lock_fork(t_philo *philo, int fork);

#endif
