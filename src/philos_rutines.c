/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_rutines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:46:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:01 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*philo_rutine(void *param)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)param;
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = miliseconds_time();
	pthread_mutex_unlock(&philo->meal_lock);
	while (checker_aprove(philo) == OK)
	{
		if (checker_aprove(philo) == OK)
			eat(philo);
		if (checker_aprove(philo) == OK)
			sleep_time(philo);
		if (checker_aprove(philo) == OK)
			think(philo);
		i++;
	}
	return (param);
}

void	sleep_time(t_philo *philo)
{
	uint64_t	current_time;

	print_message("is sleeping", philo);
	philo->last_sleep_time = miliseconds_time();
	current_time = miliseconds_time();
	while (current_time - philo->last_sleep_time < philo->time_to_sleep)
	{
		current_time = miliseconds_time();
		if (checker_aprove(philo) != OK)
			break ;
		usleep(100);
	}
}

void	think(t_philo *philo)
{
	print_message("is thinking", philo);
}

t_enum_type	checker_aprove(t_philo *philo)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(philo->eated_lock);
	if (*philo->eated == true)
		flag = 1;
	pthread_mutex_unlock(philo->eated_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == true)
		flag = 1;
	pthread_mutex_unlock(philo->dead_lock);
	if (flag == 1)
		return (KO);
	return (OK);
}
