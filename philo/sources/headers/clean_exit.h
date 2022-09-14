/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:00:26 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 12:00:39 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_EXIT_H
# define CLEAN_EXIT_H

void	clean_exit(t_philo *philos, pthread_t *threads, int len,
			t_params *params);
void	clean_all(t_philo *philos, pthread_t *threads, int len,
			t_params *params);
void	clean_params(t_params *params);
void	clean_philos(t_philo *philos, int length);

#endif
