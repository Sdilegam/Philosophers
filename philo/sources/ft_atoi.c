/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:22:34 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 10:46:42 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_overflow(const char *str, int signe, int i)
{
	unsigned long long	num;

	num = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		num = (num * 10) + (str[i] - 48);
		if (num >= INT_MAX && signe == 1)
			return (-1);
		else if (num > INT_MAX && signe == -1)
			return (0);
		i++;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	signe;

	i = 0;
	signe = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	num = ft_overflow(str, signe, i);
	return (num * signe);
}
