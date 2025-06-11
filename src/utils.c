/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:01:27 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

uint64_t	miliseconds_time(void)
{
	struct timeval	current_time;
	uint64_t		miliseconds;

	if (gettimeofday(&current_time, NULL) == -1)
		return (1);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (miliseconds);
}

void	print_message(char *str, t_philo *philo)
{
	uint64_t	current_time;

	pthread_mutex_lock(philo->write_lock);
	current_time = miliseconds_time() - philo->start_time;
	printf("%lu %d %s\n", current_time, philo->philo_id, str);
	pthread_mutex_unlock(philo->write_lock);
}
