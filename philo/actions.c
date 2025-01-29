/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:23 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 09:04:45 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	action_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (philo->state != DEAD)
		return (print_philo_state(philo, " has taken a fork\n"));
	pthread_mutex_unlock(fork);
}

void	action_eat(t_philo *philo)
{
	philo->state = EATING;
	print_philo_state(philo, " is eating\n");
	utils()->sleep_ms(data()->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->meals++;
	philo->last_meal = utils()->get_time_ms();
}

void	action_sleep(t_philo *philo)
{
	philo->state = EATING;
	print_philo_state(philo, " is sleeping\n");
	utils()->sleep_ms(data()->time_to_sleep);
}

void	action_think(t_philo *philo)
{
	philo->state = THINKING;
	print_philo_state(philo, " is thinking\n");
}

void	action_die(t_philo *philo)
{
	philo->state = DEAD;
	print_philo_state(philo, " died\n");
}
