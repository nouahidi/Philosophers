/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouahidi <nouahidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:24 by nouahidi          #+#    #+#             */
/*   Updated: 2023/02/24 15:39:39 by nouahidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);

    long long microseconds = (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;

    printf("Microseconds since epoch: %lld\n", microseconds);

    return 0;
}
