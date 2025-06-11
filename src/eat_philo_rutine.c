/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_philo_rutine.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:19:10 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:01 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->philo_id % 2 == 0)
	{
		first_fork = philo->his_fork;
		second_fork = philo->take_fork;
	}
	else
	{
		first_fork = philo->take_fork;
		second_fork = philo->his_fork;
	}
	if (take_first_fork(philo, first_fork) != OK)
		return ;
	if (take_second_fork(philo, first_fork, second_fork) != OK)
		return ;
	if (eating_time(philo, first_fork, second_fork) != OK)
		return ;
}

t_enum_type	take_first_fork(t_philo *philo, pthread_mutex_t *first_fork)
{
	if (checker_aprove(philo) == OK)
		pthread_mutex_lock(first_fork);
	else
		return (KO);
	if (checker_aprove(philo) == OK)
		print_message("has taken a fork.", philo);
	if (philo->total_philos == 1)
	{
		while (1)
		{
			if (checker_aprove(philo) != OK)
			{
				pthread_mutex_unlock(first_fork);
				return (KO);
			}
			usleep(10000);
		}
	}
	return (OK);
}

t_enum_type	take_second_fork(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	if (checker_aprove(philo) == OK)
		pthread_mutex_lock(second_fork);
	else
	{
		pthread_mutex_unlock(first_fork);
		return (KO);
	}
	if (checker_aprove(philo) == OK)
		print_message("has taken a fork", philo);
	else
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (KO);
	}
	return (OK);
}

void	eat_time(t_philo *philo, uint64_t current_time)
{
	while (current_time - philo->last_meal_time < philo->time_to_eat)
	{
		current_time = miliseconds_time();
		if (checker_aprove(philo) != OK)
		{
			break ;
		}
		usleep(100);
	}
}

t_enum_type	eating_time(t_philo *philo, pthread_mutex_t *first_fork,
		pthread_mutex_t *second_fork)
{
	uint64_t	current_time;

	current_time = miliseconds_time();
	if (checker_aprove(philo) != OK)
	{
		pthread_mutex_unlock(first_fork);
		pthread_mutex_unlock(second_fork);
		return (KO);
	}
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = miliseconds_time();
	philo->nbr_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	current_time = miliseconds_time();
	print_message("is eating", philo);
	eat_time(philo, current_time);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	return (OK);
}
