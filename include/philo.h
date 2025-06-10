/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:22:28 by pablalva          #+#    #+#             */
/*   Updated: 2025/06/10 17:02:17 by pablalva         ###   ########.fr       */
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

	pthread_mutex_t	*his_fork;
	pthread_mutex_t	*take_fork;
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

	pthread_t		checker;

	t_philo			**philos;

}					t_general;

/* if last_meal_philo >= time_die = filo dead */

/*    utils  */
long				ft_atol(char *str);
enum_type			ft_str_isdigit(char *str);
enum_type			check_arg(char **argv);

int					main(int argc, char **argv);
enum_type			parse_arg_and_init_vars(int argc, char **argv,
						t_general *program);
enum_type			init_program_vars(t_general *program, char **argv);
enum_type			init_forks(t_general *program);
void				*ft_calloc(size_t count, size_t size);
void				free_mutex_array(pthread_mutex_t *array, int len);
enum_type			init_phylo_vars(t_general *program);
enum_type			init_meal(t_general *program);
enum_type	assig_forks(t_general *program);
uint64_t	miliseconds_time(void);
void assig_start_time(t_general *program);
void	print_message(char *str, t_philo *philo);


/*   rutines   */
void checker_rutine(void *param);
#endif