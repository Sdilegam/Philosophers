/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:54:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/18 10:22:16 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_philo.h"
#include <unistd.h>
#include <pthread.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	test();
	write(1,"Philo: test.\n", 13);
	return (0);
}
