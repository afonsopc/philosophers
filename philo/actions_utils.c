/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:52 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/04 01:04:11 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	print_philo_state(t_philo *philo, char *state_str, bool stop)
{
	char	*timestamp;
	char	*id;
	char	*msg;

	pthread_mutex_lock(&data()->stop_mutex);
	if (data()->stop)
		return (pthread_mutex_unlock(&data()->stop_mutex), false);
	timestamp = utils()->get_time_ms_string(data()->start_time);
	id = utils()->lltoa(philo->id);
	msg = utils()->strjoin4(timestamp, " ", id, state_str);
	(utils()->fputstr)(1, msg);
	allocs()->free(timestamp);
	allocs()->free(id);
	allocs()->free(msg);
	if (stop)
		data()->stop = stop;
	pthread_mutex_unlock(&data()->stop_mutex);
	return (true);
}

void	action(t_philo *philo, t_action state)
{
	(utils()->fputstr)(1, "");
	pthread_mutex_lock(&philo->mutex);
	if (philo->state == DEAD
		|| (data()->number_of_times_each_philosopher_must_eat != -1
			&& philo->meals
			>= data()->number_of_times_each_philosopher_must_eat))
	{
		philo->state = DEAD;
		pthread_mutex_unlock(&philo->mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->mutex);
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

bool	kill_poor_and_hungry_philosophers(void)
{
	t_list	*philo_node;
	t_philo	*philo;

	philo_node = data()->philos;
	while (philo_node)
	{
		philo = philo_node->data;
		pthread_mutex_lock(&philo->mutex);
		if (philo->state != DEAD
			&& philo->state != EATING && philo->last_meal
			+ data()->time_to_die < utils()->get_time_ms())
		{
			pthread_mutex_unlock(&philo->mutex);
			philo->die(philo);
			return (true);
		}
		else
			pthread_mutex_unlock(&philo->mutex);
		philo_node = philo_node->next;
	}
	return (false);
}
