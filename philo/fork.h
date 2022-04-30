/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:29:06 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/17 18:43:42 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H
# include <pthread.h>
# include "defines.h"

typedef struct s_fork {
	int				id;
	pthread_mutex_t	block;
	t_bool			is_taken;
}	t_fork;

t_fork	*create_fork_list(int count);
t_fork	*get_fork(t_fork *forks, int index, int len);

#endif