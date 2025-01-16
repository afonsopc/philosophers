/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:48:49 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/16 01:02:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <allocs.h>
# include <utils.h>
# include <sys/time.h>

typedef struct timeval	t_time;
typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_state;

typedef struct s_philo
{
	int			id;
	t_state		state;
	t_time		last_meal;
	t_time		started_eating;
	t_fork		*left_fork;
	t_fork		*right_fork;
	int			meals;
	void		(*take_fork)(struct s_philo *philo, t_fork *fork);
	void		(*eat)(struct s_philo *philo);
	void		(*sleep)(struct s_philo *philo);
	void		(*think)(struct s_philo *philo);
	void		(*die)(struct s_philo *philo);
}	t_philo;

typedef struct s_fork
{
	int		id;
	bool	taken;
}	t_fork;

#endif