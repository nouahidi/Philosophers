/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:04:21 by nouahidi          #+#    #+#             */
/*   Updated: 2023/06/03 11:53:27 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_time(void)
{
	struct timeval	currentime;
	long long		currentimes;

	gettimeofday(&currentime, NULL);
	currentimes = currentime.tv_sec * 1000 + currentime.tv_usec / 1000;
	return (currentimes);
}

int	check_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (printf ("Error\n"), 1);
		i++;
	}
	if (!str[i])
		return (printf ("Error\n"), 1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i])
		return (printf ("Error\n"), 1);
	return (0);
}

int	check_time_nb_ph(t_var *var, int j)
{
	if (j == 1 && !var->nb_ph)
		printf ("Error\n");
	else if (j == 2 && var->time_die < 60)
		printf ("Error\n");
	else if (j == 3 && var->time_eat < 60)
		printf ("Error\n");
	else if (j == 4 && var->time_slp < 60)
		printf ("Error\n");
	else
		return (0);
	return (1);
}
