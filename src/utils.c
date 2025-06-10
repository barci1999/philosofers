/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 17:02:06 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_mutex_array(pthread_mutex_t *array, int len)
{
	int	size;
	int	i;

	i = 0;
	size = len;
	while (i < len)
	{
		pthread_mutex_destroy(&array[i]);
		i++;
	}
	free(array);
}
uint64_t	miliseconds_time(void)
{
	struct timeval current_time;
	uint64_t miliseconds;
	if (gettimeofday(&current_time, miliseconds) == -1)
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