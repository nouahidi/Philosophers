/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:24 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/13 12:31:21 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int	main()
{
	int pid = fork();
	if (pid == -1){
		return (1);
	}
	printf ("hello from proxesses\n");
	if (pid != 0){
		wait(NULL);
	}
	return (0);
}
