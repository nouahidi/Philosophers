/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:30 by nouahidi          #+#    #+#             */
/*   Updated: 2023/03/03 17:00:20 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long    get_time_of_day(void)
{
    struct timeval    tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void    my_sleep(long long millisecond)
{
    long long    curr;
    long long    end;

    curr = get_time_of_day();
    end = curr + millisecond;
    while (get_time_of_day() < end)
        usleep(76);
}

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

void	printer(char *msg, pthread_mutex_t *prt)
{
	pthread_mutex_lock(prt);
	printf("%s\n", msg);
	pthread_mutex_unlock(prt);
}

void	*routine(void	*arg)
{
	t_ph				*ph;
	static	long long	time;
	static	long long	res;
	// int					tim_eat;

	ph = (t_ph *)arg;
	time = ph->currentime;
	if ((ph->ind % 2))
		usleep(40);
	while (1)
	{
		pthread_mutex_lock(ph->l_fork);
		printf("%lld %d has taken a fork1\n", ft_time() - time, ph->ind);
		pthread_mutex_lock(ph->r_fork);
		printf("%lld %d has taken a fork2\n", ft_time() - time, ph->ind);
		ph->data->dide_time = ft_time() - time;
		printf("%lld %d is eating\n", ft_time() - time, ph->ind);
		usleep(ph->time_eat * 1000);
		printf("%lld %d is fi_eating\n", ft_time() - time, ph->ind);
		printf ("--------->%lld\n", ft_time() - time);
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(ph->r_fork);
		printf("%lld %d is slepping\n", ft_time() - time, ph->ind);
		usleep(ph->time_slp * 1000);
		res = ft_time() - time - (ph->time_die * 1000);
		// if ((ft_time - time) - ph->lunch_time > res)
		// 	printf ("%shere did", AC_RED);
		printf("%lld %d is fi_slepping\n", ft_time() - time, ph->ind);
	}
	return (NULL);
}

void	ft_starting(t_var *var)
{
	int i;
	int j;

	i = 1;
	var->thread = malloc(var->nb_ph * sizeof(pthread_t));
	if (!var->thread)
		ft_error(var);
	while (i <= var->nb_ph)
	{
		if (pthread_create(var->thread, NULL, routine, &var->philo[i]))
			ft_error(var);
		i++;
	}
	j = 0;
	while (j < var->nb_ph)
		pthread_join(var->thread[j++], NULL);
}

void	inf_philo(t_var *var)
{
	int	i;

	i = 1;
	// exit(0);
	// var->philo->currentime = ft_time();
	var->philo = malloc(var->nb_ph * sizeof(t_ph));
	var->prt = malloc(sizeof(pthread_mutex_t));
	if (pthread_mutex_init(var->prt, NULL))
		ft_error(var);
	while(i <= var->nb_ph)
	{
		if (pthread_mutex_init(&(var->philo->sleep), NULL))
			ft_error(var);
		var->philo[i].currentime = ft_time();
		var->philo[i].ind = i;
		var->philo[i].l_fork = &var->fork[i];
		var->philo[i].r_fork = &var->fork[(i % var->nb_ph) + 1];
		// printf ("i == %d i + 1 == %d\n", i, (i % var->nb_ph) + 1);
		var->philo[i].time_eat = var->time_eat;
		var->philo[i].time_slp = var->time_slp;
		var->philo[i].time_die = var->time_die;
		var->philo[i].prt = var->prt;
		if (pthread_create(&var->philo->thread, NULL, routine, &var->philo[i]))
			ft_error(var);
		i++;
	}
	i = 1;
	// ft_starting(var);
	while (i <= var->nb_ph)
		pthread_join(var->philo->thread, NULL);
}

void	mutex(t_var	*var)
{
	int	i;

	i = 0;
	var->fork = malloc(var->nb_ph * sizeof(pthread_mutex_t));
	if (!var->fork)
		ft_error(var);
	// var->philo->thread = malloc(var->nb_ph * sizeof(pthread_t));
	// if (!var->thread)
	// 	ft_error(var);
	while (i < var->nb_ph)
	{
		if (pthread_mutex_init(&var->fork[i++], NULL))
			ft_error(var);
	}
	// if (pthread_mutex_init(&ph->, NULL))
	// 		ft_error(ph);
	// if (pthread_mutex_init(&ph->pr, NULL))
	// 		ft_error(ph);
}

int main(int ac, char **av)
{
	int j = 1;
	t_var	var;

	if (ac == 6)
	{
		while (av[j])
		{
			check_arg(av[j], &var);
			info_philo(av[j], j, &var);
			j++;
		}
		mutex(&var);
		// ph.currentime = ft_time();
		inf_philo(&var);
		// j = 0;
		// while (j < ph.nb_ph)
		// 	pthread_join(&ph.thread[j++], NULL);
		j = 0;
	}
	else
		write (1 ,"Error args", 10);
}
