/******************************************************************************/
/*                                                                            */
/*                                                      ::::::  :::::::::::   */
/*   time_handling.c                                  +:+ :+:  :+:     :+:    */
/*                                                       +:+    +:+   +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>             +:+      +:+:+:+      */
/*                                                     +#+          +#+       */
/*   Created: 2022/07/20 13:07:09 by sdi-lega         #+#  #+#+#+#+#+#        */
/*   Updated: 2022/07/20 16:51:18 by sdi-lega        ###                      */
/*                                                                            */
/******************************************************************************/

#include "Philosophers.h"

unsigned long	convert_time(struct timeval time)
{
	return (((long double)time.tv_sec * 1000000 + (long double)time.tv_usec)
		/ 1000);
}

void	wait_mili(struct timeval start, long double duration)
{
	struct timeval	end;

	gettimeofday(&start, 0);
	gettimeofday(&end, 0);
	while (convert_time(end) - convert_time(start) < duration)
	{
		usleep(500);
		gettimeofday(&end, 0);
	}
}
