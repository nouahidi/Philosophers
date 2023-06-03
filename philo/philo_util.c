/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:45:19 by nouahidi          #+#    #+#             */
/*   Updated: 2023/06/03 11:33:37 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *st)
{
	int	i;
	int	r;
	int	nb;

	r = 1;
	nb = 0;
	i = 0;
	while ((st[i] >= 9 && st[i] <= 13) || st[i] == ' ')
		i++;
	if (st[i] == '+' || st[i] == '-')
	{
		if (st[i] == '-')
			r = -1;
	i++;
	}
	while (st[i] >= '0' && st[i] <= '9')
	{
		nb = (nb * 10) + (st[i] - '0');
		i++;
	}
	return (nb * r);
}

int	my_sleep(long long millisecond)
{
	long long	curr;
	long long	end;

	curr = ft_time();
	end = curr + millisecond;
	while (ft_time() < end)
		usleep(76);
	return (0);
}

int	my_printf(long long time, char *str, t_ph *ph)
{
	pthread_mutex_lock(&ph->data->prt);
	pthread_mutex_lock(&ph->data->d_philo);
	if (ph->data->died)
	{
		pthread_mutex_unlock(&ph->data->d_philo);
		pthread_mutex_unlock(&ph->data->prt);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->d_philo);
	printf("%lld %d %s\n", time, ph->ind, str);
	pthread_mutex_unlock(&ph->data->prt);
	return (0);
}

void	routine_norm(t_ph *ph)
{
	my_sleep(ph->data->time_eat);
	pthread_mutex_lock(&ph->data->ph_eat);
	if (ph->data->nb_eat)
		ph->data->bg_eat++;
	pthread_mutex_unlock(&ph->data->ph_eat);
	pthread_mutex_unlock(&ph->l_fork);
	pthread_mutex_unlock(ph->r_fork);
	if (my_printf(ft_time() - ph->currentime, "is sleeping", ph))
		return ;
	my_sleep(ph->data->time_slp);
	if (my_printf(ft_time() - ph->currentime, "is thinking", ph))
		return ;
}

void	*routine(void *arg)
{
	t_ph				*ph;

	ph = (t_ph *)arg;
	if ((ph->ind % 2))
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&ph->l_fork);
		if (my_printf(ft_time() - ph->currentime, "has taken a fork", ph))
			return (pthread_mutex_unlock(&ph->l_fork), NULL);
		pthread_mutex_lock(ph->r_fork);
		pthread_mutex_lock(&ph->data->eat);
		ph->beging_eat = ft_time() - ph->currentime;
		pthread_mutex_unlock(&ph->data->eat);
		if (my_printf(ft_time() - ph->currentime, "has taken a fork", ph))
			return (pthread_mutex_unlock(&ph->l_fork), \
			pthread_mutex_unlock(ph->r_fork), NULL);
		my_printf(ft_time() - ph->currentime, "is eating", ph);
		routine_norm(ph);
	}
	return (NULL);
}
