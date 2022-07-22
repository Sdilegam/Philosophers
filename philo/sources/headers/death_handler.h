/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:56:57 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 10:59:21 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEATH_HANDLER_H
# define DEATH_HANDLER_H

unsigned long	convert_time(struct timeval time);
void			clean_exit(t_philo *philos, pthread_t *threads, int len);
void			check_death(t_philo *philo, unsigned long start,
					pthread_t *threads);

#endif
