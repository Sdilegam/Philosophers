/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:59:51 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/14 12:00:05 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_LIST_H
# define PHILOSOPHERS_LIST_H

t_philo	*add_node(t_philo *last);
t_philo	*create_node(t_params *params);
#endif
