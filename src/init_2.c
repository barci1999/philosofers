/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:46:37 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 16:26:15 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

enum_type	assig_forks(t_general *program)
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
void assig_start_time(t_general *program)
{
	int i;
	i = 0;
	while (i < program->total_philos)
	{
		program->philos[i]->start_time = miliseconds_time();
		i++;
	}
}
