/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:20:20 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 16:49:57 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

enum_type	check_arg(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (ft_str_isdigit(argv[i]) == KO)
			return (KO);
	}
	if (ft_atol(argv[i]) > 200 || ft_atol(argv[1]) <= 0)
		return (KO);
	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) <= 0)
			return (KO);
		i++;
	}
	return (OK);
}

enum_type	parse_arg_and_init_vars(int argc, char **argv, t_general *program)
{
	if (argc != 5 && argc != 6)
		return (printf("Error: Invalid number of arguments\n"), KO);
	if (check_arg(argv) != KO)
		return (printf("Error: invalid Arguments\n"), KO);
	if (init_program_vars(program, argv) != OK)
		return (printf("Error: Failed to initialize the program variables.\n"),
			KO);
	if (init_phylo_vars(program) != OK)
		return (printf("Error; Failed to initialize philosophers variables.\n"),
			KO);
	if(assig_forks(program) != OK)
		return(printf("Error: Failed to asignation of forks.\n"),KO);
	assig_start_time(program);
	return (OK);
}
