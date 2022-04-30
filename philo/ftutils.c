/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:39:13 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/29 18:32:03 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include "philo.h"
#include "defines.h"

void	*ft_free(void *p)
{
	free(p);
	return (NULL);
}

t_bool	is_digit(char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_atoi(const char *str)
{
	int				ret;
	int				sign;

	ret = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && is_digit(*str))
	{
		ret = ret * 10 + ((*str) - '0');
		str++;
	}
	return (ret * sign);
}

unsigned long long	current_timestamp(unsigned long long starttime)
{
	struct timeval				t;

	gettimeofday(&t, NULL);
	return (((t.tv_sec * 1000) + (t.tv_usec / 1000)) - starttime);
}

t_bool	ft_sleep(unsigned long long usec, t_philo *p)
{
	unsigned long long	start;

	start = current_timestamp(p->start_time);
	while (start + usec > current_timestamp(p->start_time))
	{
		if (death_check(p))
			return (FT_FALSE);
		usleep(100);
	}
	return (FT_TRUE);
}
