/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 09:14:43 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <allocs.h>
# include <utils.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_state;

typedef enum e_action
{
	TAKE_LEFT_FORK,
	TAKE_RIGHT_FORK,
	THINK,
	EAT,
	SLEEP,
	DIE
}	t_action;

typedef struct s_philo
{
	int					id;
	t_state				state;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	size_t				last_meal;
	int					meals;
	void				(*take_fork)(struct s_philo *philo,
			pthread_mutex_t *fork);
	void				(*eat)(struct s_philo *philo);
	void				(*sleep)(struct s_philo *philo);
	void				(*think)(struct s_philo *philo);
	void				(*die)(struct s_philo *philo);
}	t_philo;

typedef struct s_data
{
	t_list		*philos;
	t_list		*forks;
	t_list		*threads;
	size_t		start_time;
	size_t		number_of_philosophers;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	ssize_t		number_of_times_each_philosopher_must_eat;

}	t_data;

t_data	*data(void);
void	print_philo_state(t_philo *philo, char *state_str);
bool	init(int argc, char **argv);
void	create_philosohers(void);
void	create_forks(void);
void	action_take_fork(t_philo *philo,
			pthread_mutex_t *fork);
void	action_eat(t_philo *philo);
void	action_sleep(t_philo *philo);
void	action_think(t_philo *philo);
void	action_die(t_philo *philo);
void	action(t_philo *philo, t_action state);
bool	philosopher_has_ate_enough(t_philo *philo);

#endif