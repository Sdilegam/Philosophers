/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:50:33 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 10:59:14 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

void			routine_think(t_philo *philo, unsigned long start);
void			routine_sleep(t_philo *philo, unsigned long start);
void			wait_mili(struct timeval start, long double duration);
void			routine_eat(t_philo *philo, unsigned long start, int *finished,
					int i);
unsigned long	convert_time(struct timeval time);
void			routine_take_fork(t_philo *philo, int fork,
					unsigned long start);

#endif
