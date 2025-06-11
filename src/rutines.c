/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:02:18 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:03:01 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_enum_type	create_pthreads(t_general *program)
{
	t_philo	**philos;
	int		i;

	i = 0;
	philos = program->philos;
	assig_start_time(program);
	if (pthread_create(&program->checker, NULL, checker_rutine, program) != 0)
	{
		printf("Error: fail to create checker.\n");
		return (KO);
	}
	while (i < program->total_philos)
	{
		if (pthread_create(&philos[i]->philo_thread, NULL, philo_rutine,
				philos[i]) != 0)
		{
			printf("Error: fail to create a philo pthread.\n");
			return (KO);
		}
		i++;
	}
	return (OK);
}

t_enum_type	join_pthreads(t_general *program)
{
	int		i;
	t_philo	**philos;

	philos = program->philos;
	if (pthread_join(program->checker, NULL) != 0)
	{
		printf("Error: fail in checker.\n");
		return (KO);
	}
	i = 0;
	while (i < program->total_philos)
	{
		if (pthread_join(philos[i]->philo_thread, NULL) != 0)
		{
			printf("Error: fail in a philo.\n");
			return (KO);
		}
		i++;
	}
	return (OK);
}

t_enum_type	init_rutines(t_general *program)
{
	if (create_pthreads(program) != OK)
	{
		free_all_resources(program);
		return (KO);
	}
	if (join_pthreads(program) != OK)
	{
		free_all_resources(program);
		return (KO);
	}
	return (OK);
}
