/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   philosophers_list.c                              +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/19 15:48:59 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/19 17:26:39 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#include "Philosophers.h"

t_philo	*create_node(t_g_params *params)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (0);
	node->id = 0;
	node->next = 0;
	node->previous = 0;
	node->params = params;
	return (node);
}

t_philo	*join_node(t_philo *first, t_philo *second)
{
	if (!second || !first)
		return (0);
	first->next = second;
	second->previous = first;
	return (second);
}
