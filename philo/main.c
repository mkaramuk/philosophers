/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:53:02 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/29 18:37:09 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "philo.h"
#include "ftutils.h"
#include "argparser.h"
#include "fork.h"

t_philo	*create_philos(int *datas,
						pthread_mutex_t *print_mutex,
						t_bool *is_gameover,
						t_fork **out_forks)
{
	t_fork	*forks;
	t_philo	*philos;
	int		i;

	forks = create_fork_list(datas[0]);
	*out_forks = forks;
	philos = malloc(sizeof(t_philo) * datas[0]);
	i = 0;
	while (i < datas[0])
	{
		philos[i].id = i + 1;
		philos[i].left_fork = get_fork(forks, i, datas[0]);
		philos[i].right_fork = get_fork(forks, i - 1, datas[0]);
		philos[i].time_to_eat = datas[1];
		philos[i].time_to_sleep = datas[2];
		philos[i].time_to_die = datas[3];
		philos[i].is_gameover = is_gameover;
		philos[i].eat_times = datas[4];
		philos[i].print_mutex = print_mutex;
		philos[i].has_left_fork = FT_FALSE;
		philos[i++].has_right_fork = FT_FALSE;
	}
	return (philos);
}

void	start_philos_helper(t_philo *ps, int pc, int start)
{
	int	i;

	i = start;
	while (i < pc)
	{
		ps[i].start_time = ps->start_time;
		pthread_create(&(ps[i].thread), NULL, (void *(*)(void *))philo, ps + i);
		i += 2;
	}
}

void	join_philos(t_philo *ps, int len)
{
	int		i;

	i = 0;
	while (i < len)
		pthread_join(ps[i++].thread, NULL);
}

void	main_free(int *args, t_philo *ps, t_fork *forks, \
					pthread_mutex_t *printmutex)
{
	int	i;

	i = -1;
	while (++i < args[0])
		pthread_mutex_destroy(&(forks[i].block));
	free(forks);
	free(args);
	free(ps);
	pthread_mutex_destroy(printmutex);
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	print_mutex;
	t_bool			is_gameover;
	int				*args;

	if (argc < 5)
		return (1);
	args = parse_args(argc, argv);
	if (!args)
	{
		printf("Error in arguments\n");
		return (1);
	}
	is_gameover = FT_FALSE;
	pthread_mutex_init(&print_mutex, NULL);
	philos = create_philos(args, &print_mutex, &is_gameover, &forks);
	philos->start_time = current_timestamp(0);
	start_philos_helper(philos, args[0], 0);
	usleep(1000);
	start_philos_helper(philos, args[0], 1);
	join_philos(philos, args[0]);
	main_free(args, philos, forks, &print_mutex);
	return (0);
}
