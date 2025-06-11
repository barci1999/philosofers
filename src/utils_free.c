/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:44:51 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 21:59:22 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_pthread(t_general *program)
{
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->eated_lock);
	pthread_mutex_destroy(&program->write_lock);
}

void	free_all_resources(t_general *program)
{
	int	i;

	i = 0;
	free_pthread(program);
	if (program->fork_lock)
	{
		i = 0;
		while (i < program->total_philos)
			pthread_mutex_destroy(&program->fork_lock[i++]);
		free(program->fork_lock);
	}
	if (program->philos)
	{
		i = 0;
		while (i < program->total_philos)
		{
			if (program->philos[i])
			{
				pthread_mutex_destroy(&program->philos[i]->meal_lock);
				free(program->philos[i]);
			}
			i++;
		}
		free(program->philos);
	}
}

void	free_philo_array(t_general *program)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (program->philos)
	{
		while (i < program->total_philos)
		{
			if (pthread_mutex_destroy(&program->philos[i]->meal_lock) != 0)
			{
				printf("Error: fail to destroy mutex\n");
				flag = 1;
			}
			free(program->philos[i]);
			i++;
		}
		free(program->philos);
		program->philos = NULL;
	}
}

void	free_mutex_array(pthread_mutex_t *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pthread_mutex_destroy(&array[i]);
		i++;
	}
	free(array);
}
