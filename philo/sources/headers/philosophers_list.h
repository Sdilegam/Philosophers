/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:55:32 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 11:00:36 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_LIST_H
# define PHILOSOPHERS_LIST_H

t_philo	*join_node(t_philo *first, t_philo *second);
t_philo	*create_node(t_g_params *params);

#endif
