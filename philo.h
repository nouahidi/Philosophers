/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:46:29 by nouahidi          #+#    #+#             */
/*   Updated: 2023/03/03 16:56:09 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

typedef struct inf_philo
{
	long long	dide_time;
	long long	eat;
	int			j;
}	t_data;

typedef struct philo
{
	long long				time_die;
	int				time_eat;
	int				time_slp;
	int				nb_ph;
	int				nb_eat;
	int				nb_of_eat;
	int				ind;
	long long		dide_time;
	t_data			data[200];
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	sleep;
	pthread_mutex_t	*prt;
	long long		currentime;
	pthread_t		thread;
}	t_ph;

typedef struct var
{
	int				nb_ph;
	// int				ind;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				nb_eat;
	pthread_t		*thread;
	pthread_mutex_t	*eat;
	t_ph			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*prt;
}				t_var;


int	ft_atoi(const char *st);

#endif