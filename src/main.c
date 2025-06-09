/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:33:57 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/09 21:28:17 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc,char **argv)
{
	t_general program;
	memset(&program,0,sizeof(program));
	if(parse_arg(argc,argv,&program) != OK)
		exit(2);
	return(0);
	
}