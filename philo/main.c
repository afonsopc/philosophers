/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/06 21:14:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/*
Exit Codes:
0 - Success
1 - Not enough arguments
2 - Memory allocation error
*/

void	*philo_processor(t_philo *philo)
{
	if (data()->number_of_philosophers == 1)
		return (action(philo, TAKE_RIGHT_FORK),
			utils()->safe_sleep_ms(data()->time_to_die, &data()->stop), NULL);
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(&data()->stop_mutex);
		if (philo->state == DEAD || data()->stop)
			return (pthread_mutex_unlock(&philo->mutex),
				pthread_mutex_unlock(&data()->stop_mutex), NULL);
		pthread_mutex_unlock(&data()->stop_mutex);
		pthread_mutex_unlock(&philo->mutex);
		while (1)
		{
			if (philo->id % 2)
				(action(philo, TAKE_RIGHT_FORK), action(philo, TAKE_LEFT_FORK));
			else
				(action(philo, TAKE_LEFT_FORK), action(philo, TAKE_RIGHT_FORK));
			break ;
		}
		action(philo, EAT);
		action(philo, SLEEP);
		action(philo, THINK);
	}
	return (NULL);
}

bool	philosophers_alive(void)
{
	t_list	*philo_node;
	t_philo	*philo;

	philo_node = data()->philos;
	while (philo_node)
	{
		philo = philo_node->data;
		pthread_mutex_lock(&philo->mutex);
		if (philo->state != DEAD)
			return (pthread_mutex_unlock(&philo->mutex), true);
		pthread_mutex_unlock(&philo->mutex);
		philo_node = philo_node->next;
	}
	return (false);
}

void	*philo_mastermind(void)
{
	while (philosophers_alive())
	{
		if (kill_poor_and_hungry_philosophers())
			break ;
		usleep(50);
	}
	return (NULL);
}

void	start_simulation(void)
{
	t_list		*philo_node;
	t_philo		*philo;
	pthread_t	*thread;

	data()->start_time = utils()->get_time_ms();
	philo_node = data()->philos;
	while (philo_node)
	{
		thread = allocs()->calloc(1, sizeof(pthread_t));
		philo = philo_node->data;
		philo_node = philo_node->next;
		pthread_create(thread, NULL,
			(void *(*)(void *))philo_processor, philo);
		(utils()->list_append)(&data()->threads, thread);
	}
	thread = allocs()->calloc(1, sizeof(pthread_t));
	pthread_create(thread, NULL,
		(void *(*)(void *))philo_mastermind, NULL);
	pthread_join(*thread, NULL);
	join_threads();
}

int	main(int argc, char **argv)
{
	if (!init(argc, argv))
		return (1);
	data()->philos = NULL;
	data()->forks = NULL;
	create_forks();
	create_philosohers();
	start_simulation();
	destroy_mutexes();
	utils()->exit(0);
}
