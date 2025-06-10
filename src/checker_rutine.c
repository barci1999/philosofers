/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rutine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:37:55 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 17:03:39 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void checker_rutine(void *param)
{
	t_general *program;
	program = param;
	while (1)
	{
		usleep(100);
		if(philo_death(program) == OK)
			break;
		if(program->total_eats >= 0 && all_philo_eated(program) == OK)
			break;
	}
	return(param);
}
enum_type philo_death(t_general *program)
{
	int i;
	uint64_t eat_time;
	while (i < program->total_philos)
	{
		pthread_mutex_lock(&program->philos[i]->meal_lock);
		if(program->philos[i]->last_meal_time == 0)
			eat_time = 0;
		else
			eat_time = miliseconds_time() - program->philos[i]->last_meal_time;
		pthread_mutex_unlock(&program->philos[i]->meal_lock);
		if(eat_time > program->time_to_die)
		{
			pthread_mutex_lock(&program->dead_lock);
			program->philo_dead = true;
			print_message("died",program->philos[i]);
			pthread_mutex_unlock(&program->dead_lock);
			return(OK);
		}
		i++;
	}
	return(KO);
	
}