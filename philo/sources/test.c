/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:54:50 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/18 04:21:20 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int test(void)
{
	write(1, "HELLO ca va", 5);
	return (1);
}