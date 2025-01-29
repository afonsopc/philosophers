/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:23 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 00:38:16 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	action_take_fork(t_philo *philo, t_fork *fork, bool right_fork)
{
	if (right_fork)
		philo->right_fork = fork;
	else
		philo->left_fork = fork;
	fork->taken = true;
	print_philo_state(philo, " has taken a fork\n");
}

void	action_eat(t_philo *philo)
{
	philo->state = EATING;
	print_philo_state(philo, " is eating\n");
	utils()->sleep_ms(data()->time_to_eat);
	philo->right_fork->taken = false;
	philo->left_fork->taken = false;
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
