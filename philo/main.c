/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/04 01:15:21 by afpachec         ###   ########.fr       */
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
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (philo->state == DEAD)
			return (pthread_mutex_unlock(&philo->mutex), NULL);
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
		if (philo->state != DEAD)
			return (true);
		philo_node = philo_node->next;
	}
	return (false);
}

void	*philo_mastermind(void)
{
	while (philosophers_alive())
		if (kill_poor_and_hungry_philosophers())
			break ;
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
	pthread_create(thread, NULL,
		(void *(*)(void *))philo_mastermind, NULL);
	pthread_join(*thread, NULL);
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
	utils()->exit(0);
}
