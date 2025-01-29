/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:52 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 09:22:52 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_philo_state(t_philo *philo, char *state_str)
{
	char	*timestamp;
	char	*id;
	char	*msg;

	timestamp = utils()->get_time_ms_string(data()->start_time);
	id = utils()->lltoa(philo->id);
	msg = utils()->strjoin4(timestamp, " ", id, state_str);
	(utils()->fputstr)(1, msg);
	allocs()->free(timestamp);
	allocs()->free(id);
	allocs()->free(msg);
}

bool	philosopher_has_ate_enough(t_philo *philo)
{
	return (data()->number_of_times_each_philosopher_must_eat != -1
		&& philo->meals >= data()->number_of_times_each_philosopher_must_eat);
}

void	action(t_philo *philo, t_action state)
{
	if (philo->state == DEAD || philosopher_has_ate_enough(philo))
	{
		philo->state = DEAD;
		return ;
	}
	if (state == TAKE_LEFT_FORK)
		philo->take_fork(philo, philo->left_fork);
	else if (state == TAKE_RIGHT_FORK)
		philo->take_fork(philo, philo->right_fork);
	else if (state == EAT)
		philo->eat(philo);
	else if (state == SLEEP)
		philo->sleep(philo);
	else if (state == THINK)
		philo->think(philo);
	else if (state == DIE)
		philo->die(philo);
}
