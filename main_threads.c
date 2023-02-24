/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:30 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/24 16:32:05 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(t_var *ph)
{
	(void)ph;
	write (1,"Error\n",6);
	exit(0);
}

long long	ft_time()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    long long currentTimeMs = currentTime.tv_sec * 1000 + currentTime.tv_usec / 1000;
    return (currentTimeMs);
}

void	check_arg(char *str, t_var *ph)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			ft_error(ph);
		i++;
	}
	if (!str[i])
		ft_error(ph);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		ft_error(ph);
}

void	info_philo(char *str, int j, t_var	*ph)
{
	if (j == 1)
		ph->nb_ph = ft_atoi(str);
	else if (j == 2)
		ph->time_die = ft_atoi(str);
	else if (j == 3)
		ph->time_eat = ft_atoi(str);
	else if (j == 4)
		ph->time_slp = ft_atoi(str);
	else if (j == 5)
		ph->nb_eat = ft_atoi(str);
}

void	*routine(void	*arg)
{
	t_ph *philo;

	philo = (t_ph *)arg;
	while (1)
	{
		if (philo->ind % 2)
			usleep(100000);
		pthread_mutex_lock(&philo->r_fork);
		pthread_mutex_lock(&philo->l_fork);
		printf("%lld philo %d has taken a fork1\n", ft_time() - philo->vars->currentime, philo->ind);
		printf("%lld philo %d has taken a fork2\n", ft_time() - philo->vars->currentime, philo->ind);
		printf ("philo %d eating\n", philo->ind);
		usleep(philo->vars->time_eat);
		usleep(philo->vars->time_eat * 1000);
		pthread_mutex_unlock(&philo->r_fork);
		pthread_mutex_unlock(&philo->l_fork);
	}
	return (NULL);
}


void	inf_philo(t_ph	*ph, t_var *var)
{
	int	i;

	i = 0;
	while(i < var->nb_ph)
	{
		ph[i].ind = i + 1;
		ph[i].r_fork = var->fork[i];
		ph[i].l_fork = var->fork[(i + 1) % var->nb_ph];
		ph[i].vars = var;
		pthread_create(&ph[i].thread, NULL, routine, &ph[i]);
		i++;
	}
	// printf ("--->%d\n", ind);
}

void	mutex(t_var	*ph)
{
	int	i;

	ph->fork = malloc(ph->nb_ph * sizeof(mutex));
	i = 0;
	while (i < ph->nb_ph)
	{
		if (pthread_mutex_init(&ph->fork[i++], NULL))
			ft_error(ph);
	}
	if (pthread_mutex_init(&ph->pr, NULL))
			ft_error(ph);
}

int main(int ac, char **av)
{
	int j = 1;
	t_var	ph;
	t_ph *philo;

	ph.currentime = ft_time();
	if (ac == 6)
	{
		while (av[j])
		{
			check_arg(av[j], &ph);
			info_philo(av[j], j, &ph);
			j++;
		}
		philo = malloc(ph.nb_ph * sizeof(mutex));
		mutex(&ph);
		inf_philo(philo, &ph);
		j = 0;
		while (j < ph.nb_ph)
			pthread_join(philo[j++].thread, NULL);
		j = 0;
	}
	else
		write (1 ,"Error args", 10);
}
