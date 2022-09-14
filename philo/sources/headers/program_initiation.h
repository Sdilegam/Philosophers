/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_inititation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:57:12 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 11:58:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_INITIATION_H
# define PROGRAM_INITIATION_H

int				ft_atoi(const char *str);
unsigned long	convert_time(struct timeval time);
t_params		initiate_parameters(int argc, char **argv);
void			join_threads(pthread_t *threads, int n_philos);
void			*routine(void *bridge);
void			create_threads(pthread_t *threads, t_philo *philosopher,
					int n_philos);
int				set_global_mutexes(t_params *params);
int				check_params(t_params *p);
#endif
