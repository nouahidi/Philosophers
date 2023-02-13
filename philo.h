/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:46:29 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/13 16:05:46 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct philo
{
	int	nb_ph;
	int	time_die;
	int	time_eat;
	int	time_slp;
	int	nb_eat;
}				t_var;

int	ft_atoi(const char *st);


#endif