/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 20:14:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/09 21:54:27 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void free_mutex_array(pthread_mutex_t *array,int len)
{
	int size;
	int i;
	i = 0;
	size = len;
	while (i < len)
	{
		pthread_mutex_destroy(&array[i]);
		i++;
	}
	free(array);
}
void free_philos_array(t_general *program)
{
	int i;
	i = 0;
	if(program->philos)
	{
		while (i > program->total_philos)
		{
			
		}
		
	}
}