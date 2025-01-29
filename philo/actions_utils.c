/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 23:57:52 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/29 08:40:04 by afpachec         ###   ########.fr       */
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
