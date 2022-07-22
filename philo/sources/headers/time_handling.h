/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handling.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:55:01 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/22 10:59:54 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HANDLING_H
# define TIME_HANDLING_H

void			wait_mili(struct timeval start, long double duration);
unsigned long	convert_time(struct timeval time);

#endif
