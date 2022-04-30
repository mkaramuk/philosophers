/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:41:23 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/28 19:20:49 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"
#include "ftutils.h"

t_bool	action(t_philo *p, char *msg, unsigned long wait)
{
	t_bool	ret;

	ret = FT_TRUE;
	pthread_mutex_lock(p->print_mutex);
	if (!*(p->is_gameover))
		printf("%llu %d %s\n", current_timestamp(p->start_time), p->id, msg);
	else
		ret = FT_FALSE;
	pthread_mutex_unlock(p->print_mutex);
	if (wait && ret)
		return (ft_sleep(wait, p));
	return (ret);
}

t_bool	death_check(t_philo *p)
{
	if (p && current_timestamp(p->start_time) > p->death_time)
	{
		action(p, "died", 0);
		pthread_mutex_lock(p->print_mutex);
		*(p->is_gameover) = FT_TRUE;
		pthread_mutex_unlock(p->print_mutex);
		return (FT_TRUE);
	}
	return (FT_FALSE);
}

t_bool	ph_eat(t_philo *p)
{
	return (action(p, "is eating", p->time_to_eat));
}

t_bool	ph_think(t_philo *p)
{
	return (action(p, "is thinking", 0));
}

t_bool	ph_sleep(t_philo *p)
{
	return (action(p, "is sleeping", p->time_to_sleep));
}
