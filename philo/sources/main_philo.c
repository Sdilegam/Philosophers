/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:54:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/18 12:13:47 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_philo.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void *routine (void *number)
{
	int *test;
	int index = -1;
	test = (int *)number;
	while (++index != 500000)
	{
		(*test)++;
	}
	return(test);
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int test = 0;
	pthread_t p1 = 0;
	pthread_create(&p1, NULL, &routine, &test);
	pthread_t p2 = 0;
	pthread_create(&p2, NULL, &routine, &test);
	pthread_join(p1, NULL);
	printf("%d\n", test);
	pthread_join(p2, NULL);
	printf("%d\n", test);
	return (0);
}
