/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdi-lega <sdi-lega@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:00:13 by sdi-lega          #+#    #+#             */
/*   Updated: 2022/07/18 13:11:02 by sdi-lega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Philosophers_H
# define Philosophers_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_philosopher{
	int	id;
	
	struct s_philosopher *next;
	struct s_philosopher *previous;
} t_philosopher;

typedef struct s_g_params{
	
	int	id;
	t_philosopher philosophers;
	
}	t_g_patams;



#endif /* TYPE_DEFINITION_H */
