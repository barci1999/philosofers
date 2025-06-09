/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:22:28 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/09 21:57:33 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum enum_type
{
	OK,
	KO,
}					enum_type;

typedef struct s_philo
{
	pthread_t		philo_thread;

	int				total_philos;
	int				total_eats;

	int				philo_id;
	int				nbr_eaten;

	bool			*dead;
	bool			*eated;

	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		start_time;
	uint64_t		last_meal_time;
	uint64_t		last_sleep_time;

	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	meal_lock;

	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*eated_lock;
	pthread_mutex_t	*write_lock;

}					t_philo;
typedef struct s_general
{
	int				total_philos;
	int				total_eats;

	bool			philo_dead;
	bool			philo_eated;

	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		start_time;

	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eated_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*fork_lock;

	pthread_t		waiter;

	t_philo			**philos;

}					t_general;

/* if last_meal_philo >= time_die = filo dead */

/*    utils  */
long				ft_atol(char *str);
enum_type			ft_str_isdigit(char *str);
enum_type			check_arg(char **argv);

int					main(int argc, char **argv);
enum_type			parse_arg(int argc, char **argv, t_general *program);
enum_type			init_program_vars(t_general *program, char **argv);
enum_type			init_forks(t_general *program);
void				*ft_calloc(size_t count, size_t size);
void				free_mutex_array(pthread_mutex_t *array, int len);
enum_type			init_phylo_vars(t_general *program);
enum_type			init_meal(t_general *program);
#endif