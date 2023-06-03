/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:30 by nouahidi          #+#    #+#             */
/*   Updated: 2023/06/03 12:06:04 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include<fcntl.h>

void	stating_norm2(t_var *var, t_data *data, int j)
{
	pthread_mutex_lock(&data->prt);
	printf("%lld %d %s\n", ft_time() - \
	var->philo[j].currentime, var->philo[j].ind, "is dead");
	pthread_mutex_lock(&data->d_philo);
	data->died = 1;
	pthread_mutex_unlock(&data->d_philo);
	pthread_mutex_unlock(&data->eat);
	pthread_mutex_unlock(&data->prt);
}

void	starting_norm(t_data *data)
{
	pthread_mutex_unlock(&data->eat);
	pthread_mutex_unlock(&data->prt);
	pthread_mutex_lock(&data->d_philo);
	data->died = 1;
	pthread_mutex_unlock(&data->d_philo);
	pthread_mutex_unlock(&data->ph_eat);
	pthread_mutex_unlock(&data->prt);
}

void	starting(t_var *var, t_data *data)
{
	static int	j;

	inf_philo(var, data);
	while (1)
	{
		pthread_mutex_lock(&data->eat);
		pthread_mutex_lock(&data->ph_eat);
		if (data->nb_eat && data->bg_eat >= (data->nb_eat * data->nb_ph))
		{
			if (++data->num_eat > data->nb_eat)
			{
				starting_norm(data);
				break ;
			}
		}
		pthread_mutex_unlock(&data->ph_eat);
		if (ft_time() - var->philo[j].currentime - \
		var->philo[j].beging_eat >= data->time_die)
		{
			stating_norm2(var, data, j);
			break ;
		}
		pthread_mutex_unlock(&data->eat);
		j = (j + 1) % var->nb_ph;
	}
}

void	main_norm(t_var *var, t_data *data)
{
	int	j;

	j = 0;
	while (j < var->nb_ph && data->nb_ph != 1)
		pthread_join(var->philo[j++].thread, NULL);
	free(var->philo);
	free(data);
}

int	main(int ac, char **av)
{
	int		j;
	t_var	var;
	t_data	*data;

	j = 1;
	if (ac == 6 || ac == 5)
	{
		while (av[j])
		{
			if (check_arg(av[j]))
				return (1);
			if (info_philo(av[j], j, &var))
				return (1);
			j++;
		}
		if (j == 6 && var.nb_eat == 0)
			return (1);
		if (j == 5)
			var.nb_eat = 0;
		data = malloc(sizeof(t_data));
		starting(&var, data);
		main_norm(&var, data);
	}
	else
		write (1, "Error args", 10);
}
