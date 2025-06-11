/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:46:37 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:01 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_enum_type	assig_forks(t_general *program)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = program->philos;
	if (program->total_philos == 1)
	{
		philos[0]->his_fork = &program->fork_lock[0];
	}
	while (i < program->total_philos)
	{
		philos[i]->his_fork = &program->fork_lock[i];
		i++;
	}
	i = 0;
	while (i < program->total_philos)
	{
		if (i == program->total_philos - 1)
			philos[i]->take_fork = &program->fork_lock[0];
		else
			philos[i]->take_fork = &program->fork_lock[i + 1];
		i++;
	}
	return (OK);
}

void	assig_start_time(t_general *program)
{
	int	i;

	i = 0;
	while (i < program->total_philos)
	{
		program->philos[i]->start_time = miliseconds_time();
		i++;
	}
}

t_enum_type	init_philos_array(t_general *program)
{
	int	i;
	int	total_philos;

	total_philos = program->total_philos;
	program->philos = malloc(sizeof(t_philo *) * total_philos);
	if (!program->philos)
		return (KO);
	i = 0;
	while (i < program->total_philos)
	{
		program->philos[i] = malloc(sizeof(t_philo));
		if (!program->philos[i])
		{
			while (i > 0)
				free(program->philos[--i]);
			free(program->philos);
			return (KO);
		}
		i++;
	}
	return (OK);
}
