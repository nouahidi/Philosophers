/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:46:29 by nouahidi          #+#    #+#             */
/*   Updated: 2023/06/03 11:52:32 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdarg.h>
# include <string.h>

typedef struct data
{
	int				time_slp;
	int				nb_ph;
	int				bg_eat;
	int				died;
	int				time_eat;
	int				time_die;
	int				nb_eat;
	int				num_eat;
	pthread_mutex_t	prt;
	pthread_mutex_t	time;
	pthread_mutex_t	slp;
	pthread_mutex_t	ph_eat;
	pthread_mutex_t	d_philo;
	pthread_mutex_t	eat;
}					t_data;
typedef struct philo
{
	int				nb_ph;
	int				ind;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	long long		currentime;
	long long		beging_eat;
	int				times_ate;
	pthread_t		thread;
	struct data		*data;
}					t_ph;

typedef struct var
{
	int				nb_ph;
	int				died;
	int				time_die;
	int				time_eat;
	int				time_slp;
	int				nb_eat;
	int				bg_eat;
	t_ph			*philo;
}					t_var;

int			ft_atoi(const char *st);
int			ft_printf(const char *str, ...);
void		*routine(void *arg);
int			my_printf(long long time, char *str, t_ph *ph);
int			inf_philo(t_var *var, t_data *data);
int			mutex(t_var	*var);
int			my_sleep(long long millisecond);
int			norm_routine(t_ph *ph);
int			norm_routine_2(t_ph *ph);
void		*routine(void *arg);
int			check_time_nb_ph(t_var *var, int j);
int			check_arg(char *str);
long long	ft_time(void);
void		ft_data(t_var *var, t_data *data);
int			info_philo(char *str, int j, t_var	*var);
void		inf_philo_norm(t_var *var);

#endif
