/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 00:58:42 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 08:37:07 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	init(int argc, char **argv)
{
	(void)argv;
	if (!init_utils())
		return (false);
	if (argc < 5 || argc > 6)
		return ((utils()->fputstr)(2, "Error: Not enough arguments\n"), false);
	if (!init_allocs())
		return (false);
	if (!utils()->is_number(argv[1]) || !utils()->is_number(argv[2])
		|| !utils()->is_number(argv[3]) || !utils()->is_number(argv[4])
		|| (argc == 6 && !utils()->is_number(argv[5])))
		return ((utils()->fputstr)(2, "Error: Invalid arguments\n"), false);
	data()->number_of_philosophers = utils()->atoll(argv[1]);
	data()->time_to_die = utils()->atoll(argv[2]);
	data()->time_to_eat = utils()->atoll(argv[3]);
	data()->time_to_sleep = utils()->atoll(argv[4]);
	data()->number_of_times_each_philosopher_must_eat = -1;
	if (argc != 6)
		return (true);
	data()->number_of_times_each_philosopher_must_eat = utils()->atoll(argv[5]);
	return (true);
}

void	create_philosohers(void)
{
	size_t	i;
	t_philo	*philo;
	size_t	left_fork_id;

	i = -1;
	while (++i < data()->number_of_philosophers)
	{
		philo = allocs()->calloc(1, sizeof(t_philo));
		philo->id = i;
		left_fork_id = i - 1;
		if (i == 0)
			left_fork_id = data()->number_of_philosophers - 1;
		philo->left_fork = utils()->list_get(data()->forks, left_fork_id)->data;
		philo->right_fork = utils()->list_get(data()->forks, i)->data;
		philo->take_fork = action_take_fork;
		philo->eat = action_eat;
		philo->sleep = action_sleep;
		philo->think = action_think;
		philo->die = action_die;
		philo->last_meal = utils()->get_time_ms();
		(utils()->list_append)(&data()->philos, philo);
	}
}

void	create_forks(void)
{
	size_t	i;
	t_fork	*fork;

	i = -1;
	while (++i < data()->number_of_philosophers)
	{
		fork = allocs()->calloc(1, sizeof(t_fork));
		fork->id = i;
		(utils()->list_append)(&data()->forks, fork);
	}
}
