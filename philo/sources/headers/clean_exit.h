/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:53:55 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 10:59:18 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_EXIT_H
# define CLEAN_EXIT_H

void	clean_exit(t_philo *philos, pthread_t *threads, int len);
void	clean_all(t_philo *philos, pthread_t *threads, int len);
void	clean_params(t_g_params *params);
void	clean_philos(t_philo *philos, int length);

#endif
