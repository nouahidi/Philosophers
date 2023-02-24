/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:46:29 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/24 16:00:00 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct var
{
	int				nb_ph;
	int				ind;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				nb_eat;
	long long		currentime;
	pthread_mutex_t	pr;
	pthread_mutex_t	*fork;
}				t_var;

typedef struct philo
{
	int ind;
	t_var *vars;
	pthread_t thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
}	t_ph;

int	ft_atoi(const char *st);

#endif