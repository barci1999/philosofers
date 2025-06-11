/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:44:58 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:01 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_enum_type	init_program_vars(t_general *program, char **argv)
{
	program->total_philos = ft_atol(argv[1]);
	program->time_to_die = ft_atol(argv[2]);
	program->time_to_eat = ft_atol(argv[3]);
	program->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		program->total_eats = ft_atol(argv[5]);
	else
		program->total_eats = -1;
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (KO);
	if (pthread_mutex_init(&program->eated_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->dead_lock), KO);
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->eated_lock),
			pthread_mutex_destroy(&program->dead_lock), KO);
	if (init_forks(program) != OK)
	{
		pthread_mutex_destroy(&program->dead_lock);
		pthread_mutex_destroy(&program->write_lock);
		pthread_mutex_destroy(&program->eated_lock);
		return (KO);
	}
	return (OK);
}

t_enum_type	init_forks(t_general *program)
{
	int	i;
	int	size;

	size = program->total_philos;
	i = 0;
	program->fork_lock = ft_calloc(size, sizeof(pthread_mutex_t));
	if (!program->fork_lock)
		return (KO);
	while (i < program->total_philos)
	{
		if (pthread_mutex_init(&program->fork_lock[i], NULL) != 0)
		{
			free_mutex_array(program->fork_lock, i);
			return (KO);
		}
		i++;
	}
	return (OK);
}

t_enum_type	init_meal(t_general *program)
{
	int		i;
	t_philo	**philo;

	i = 0;
	philo = program->philos;
	while (i < program->total_philos)
	{
		if (pthread_mutex_init(&philo[i]->meal_lock, NULL) != 0)
		{
			while (--i > 0)
				pthread_mutex_destroy(&philo[i]->meal_lock);
			return (KO);
		}
		i++;
	}
	return (OK);
}

t_enum_type	init_phylo_vars(t_general *program)
{
	int	i;

	i = 0;
	while (i < program->total_philos)
	{
		program->philos[i]->philo_id = i + 1;
		program->philos[i]->dead = &program->philo_dead;
		program->philos[i]->total_philos = program->total_philos;
		program->philos[i]->total_eats = program->total_eats;
		program->philos[i]->nbr_eaten = 0;
		program->philos[i]->last_meal_time = 0;
		program->philos[i]->eated = &program->philo_eated;
		program->philos[i]->time_to_die = program->time_to_die;
		program->philos[i]->time_to_eat = program->time_to_eat;
		program->philos[i]->time_to_sleep = program->time_to_sleep;
		program->philos[i]->dead_lock = &program->dead_lock;
		program->philos[i]->eated_lock = &program->eated_lock;
		program->philos[i]->write_lock = &program->write_lock;
		i++;
	}
	return (OK);
}
