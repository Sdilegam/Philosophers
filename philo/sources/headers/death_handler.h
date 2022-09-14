/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:00:44 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 12:00:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEATH_HANDLER_H
# define DEATH_HANDLER_H

unsigned long	convert_time(struct timeval time);
void			check_death(t_philo *philo, unsigned long start);
int				check_finished(t_philo *philo);

#endif
