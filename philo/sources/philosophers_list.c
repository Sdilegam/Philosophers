/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:48:59 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/09/08 10:29:52 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

t_philo	*create_node(t_params *params)
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

t_philo	*add_node(t_philo *last)
{
	t_philo	*to_add;

	if (!last)
		return (0);
	to_add = create_node(last->params);
	if (!to_add)
		return (0);
	to_add->id = last->id + 1;
	last->next = to_add;
	to_add->previous = last;
	return (to_add);
}
