/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:10:43 by nouahidi          #+#    #+#             */
/*   Updated: 2023/06/03 11:50:12 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	inf_philo(t_var *var, t_data *data)
{
	int			i;
	long long	tmp;

	ft_data(var, data);
	tmp = ft_time();
	i = -1;
	inf_philo_norm(var);
	while (++i < var->nb_ph)
	{
		var->philo[i].currentime = tmp;
		var->philo[i].ind = i + 1;
		var->philo[i].beging_eat = 0;
		var->philo[i].data = data;
		if (pthread_create(&var->philo[i].thread, NULL, \
		routine, &var->philo[i]))
			return (1);
	}
	return (0);
}

int	info_philo(char *str, int j, t_var	*var)
{
	if (j == 1)
		var->nb_ph = ft_atoi(str);
	else if (j == 2)
		var->time_die = ft_atoi(str);
	else if (j == 3)
		var->time_eat = ft_atoi(str);
	else if (j == 4)
		var->time_slp = ft_atoi(str);
	else if (j == 5)
		var->nb_eat = ft_atoi(str);
	if (check_time_nb_ph(var, j))
		return (1);
	return (0);
}

void	ft_data(t_var *var, t_data *data)
{
	pthread_mutex_init(&data->prt, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->time, NULL);
	pthread_mutex_init(&data->slp, NULL);
	pthread_mutex_init(&data->ph_eat, NULL);
	pthread_mutex_init(&data->d_philo, NULL);
	data->time_slp = var->time_slp;
	data->time_eat = var->time_eat;
	data->time_die = var->time_die;
	data->nb_ph = var->nb_ph;
	data->died = 0;
	data->bg_eat = 0;
	data->num_eat = 0;
	data->nb_eat = var->nb_eat;
}

void	inf_philo_norm(t_var *var)
{
	int		i;

	i = -1;
	var->philo = malloc((var->nb_ph) * sizeof(t_ph));
	var->died = 0;
	i = -1;
	while (++i < var->nb_ph)
		pthread_mutex_init(&var->philo[i].l_fork, NULL);
	i = -1;
	while (++i < var->nb_ph)
	{
		if (i + 1 == var->nb_ph)
			var->philo[i].r_fork = &var->philo[0].l_fork;
		else
			var->philo[i].r_fork = &var->philo[i + 1].l_fork;
	}
}
