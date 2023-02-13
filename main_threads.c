/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:23:30 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/13 16:10:43 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			exit(0);
		i++;
	}
	if (!str[i])
		exit(1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			exit(0);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	int j = 1;
	t_var	ph;
	if (ac == 5)
	{
		while (av[j])
		{
			check_ar(av[j]);
			info_philo(av[j], j, &ph);
		}
	}
}
