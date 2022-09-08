/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:48:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 09:29:14 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_philo	*create_node(t_g_params *params)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (0);
	node->id = 1;
	node->next = 0;
	node->previous = node;
	node->params = params;
	node->lfork = 0;
	node->last_ate = params->start_time;
	node->rfork = 0;
	return (node);
}

t_philo	*join_node(t_philo *first, t_philo *second)
{
	if (!first || !second)
		return (0);
	second->id = first->id + 1;
	first->next = second;
	second->previous = first;
	return (second);
}
