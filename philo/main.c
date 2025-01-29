/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 23:43:36 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 08:41:01 by afpachec         ###   ########.fr       */
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
		while (1)
		{
			if (philo->last_meal + data()->time_to_die < utils()->get_time_ms())
				return (philo->die(philo), NULL);
			if (!philo->left_fork->taken && philo->right_fork->taken)
				continue ;
			philo->take_fork(philo, philo->left_fork, false);
			philo->take_fork(philo, philo->right_fork, true);
			break ;
		}
		philo->eat(philo);
		philo->sleep(philo);
		philo->think(philo);
	}
	return (NULL);
}

void	start_simulation(void)
{
	t_list		*philo_node;
	t_philo		*philo;
	pthread_t	*thread;
	size_t		i;

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
	i = -1;
	while (++i < data()->number_of_philosophers)
		pthread_join(
			(*(pthread_t *)utils()->list_get(data()->threads, i)->data), NULL);
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
