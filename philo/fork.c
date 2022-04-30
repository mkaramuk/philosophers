/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:37:30 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/28 18:38:31 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fork.h"

t_fork	*create_fork_list(int count)
{
	t_fork	*ret;
	int		id;

	id = 0;
	ret = malloc(sizeof(t_fork) * count);
	while (id < count)
	{
		ret[id].id = id + 1;
		ret[id].is_taken = FT_FALSE;
		pthread_mutex_init(&(ret[id].block), NULL);
		id++;
	}
	return (ret);
}

t_fork	*get_fork(t_fork *forks, int index, int len)
{
	if (index < 0)
		index += len;
	return (forks + index);
}
