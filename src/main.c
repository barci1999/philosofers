/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:33:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/11 22:01:58 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_general	program;

	memset(&program, 0, sizeof(program));
	if (parse_arg_and_init_vars(argc, argv, &program) != OK)
		exit(2);
	if (init_rutines(&program) != OK)
		exit(2);
	free_all_resources(&program);
	return (0);
}
