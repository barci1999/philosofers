/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutines.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 16:02:18 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 16:53:47 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
enum_type create_pthreads(t_general *program)
{
	t_philo **philos;
	int i;
	i = 0;
	assig_start_time(program);
	if(pthread_create(&program->checker,NULL,checker_rutine,program) != 0)
	{
		
	}
	
}


enum_type init_rutines(t_general *program)
{
	if(create_pthreads(program) != OK)
	{

	}
	if()
	{}
}