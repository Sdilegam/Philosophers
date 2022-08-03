/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:22:34 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/08/03 15:25:19 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_overflow(const char *str)
{
	unsigned long long	num;
	int					i;

	i = -1;
	num = 0;
	while (str[++i])
	{
		num = (num * 10) + (str[i] - 48);
		if (num >= INT_MAX)
			return (-1);
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;

	i = -1;
	num = 0;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (-1);
	num = ft_overflow(str);
	return (num);
}
