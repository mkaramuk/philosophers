/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:25:54 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/29 18:11:30 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <pthread.h>
# include "defines.h"
# include "fork.h"

typedef struct s_philo {
	pthread_t			thread;
	pthread_mutex_t		*print_mutex;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_bool				*is_gameover;
	t_bool				has_left_fork;
	t_bool				has_right_fork;
	int					id;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	long long			eat_times;
	unsigned long long	start_time;
	unsigned long long	death_time;
}	t_philo;

t_bool	action(t_philo *p, char *msg, unsigned long wait);
t_bool	death_check(t_philo *p);
t_bool	ph_eat(t_philo *p);
t_bool	ph_think(t_philo *p);
t_bool	ph_sleep(t_philo *p);
t_bool	ph_take_forks(t_philo *p);
t_bool	ph_drop_forks(t_philo *p);
void	free_philos(t_philo *p, int pc);
void	*philo(t_philo *vp);

#endif