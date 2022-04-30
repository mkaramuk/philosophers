/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoextras.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:46:12 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/29 18:39:40 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ftutils.h"
#include "fork.h"
#include "philo.h"
#include <stdio.h>

static t_bool	take_fork(t_philo *p, t_fork *fork, t_bool *hasfork)
{
	pthread_mutex_lock(&(fork->block));
	if (!fork->is_taken && !*hasfork)
	{
		if (!action(p, "has taken a fork", 0))
		{
			pthread_mutex_unlock(&(fork->block));
			return (FT_FALSE);
		}
		fork->is_taken = FT_TRUE;
		*hasfork = FT_TRUE;
	}
	pthread_mutex_unlock(&(fork->block));
	return (FT_TRUE);
}

static void	drop_fork(t_bool *hasfork, t_fork *fork)
{
	pthread_mutex_lock(&(fork->block));
	*hasfork = FT_FALSE;
	fork->is_taken = FT_FALSE;
	pthread_mutex_unlock(&(fork->block));
}

t_bool	ph_drop_forks(t_philo *p)
{
	drop_fork(&(p->has_left_fork), p->left_fork);
	drop_fork(&(p->has_right_fork), p->right_fork);
	return (FT_TRUE);
}

t_bool	ph_take_forks(t_philo *p)
{
	while (!p->has_right_fork || !p->has_left_fork)
	{
		if (!take_fork(p, p->left_fork, &(p->has_left_fork)) || \
			!take_fork(p, p->right_fork, &(p->has_right_fork)) || \
			death_check(p))
			return (FT_FALSE);
	}
	p->death_time = current_timestamp(p->start_time) + p->time_to_die;
	return (FT_TRUE);
}

void	*philo(t_philo *p)
{
	p->death_time = current_timestamp(p->start_time) + p->time_to_die;
	while (p->eat_times--)
	{
		if (!ph_take_forks(p) || \
			!ph_eat(p) || \
			!ph_drop_forks(p) || \
			!ph_sleep(p) || \
			!ph_think(p))
			break ;
	}
	return (NULL);
}
