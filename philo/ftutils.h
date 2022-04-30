/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:39:09 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/28 18:48:06 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTUTILS_H
# define FTUTILS_H
# include "defines.h"
# include "philo.h"

unsigned long long	current_timestamp(unsigned long long starttime);
t_bool				ft_sleep(unsigned long long usec, t_philo *p);
int					ft_atoi(const char *str);
void				*ft_free(void *p);
t_bool				is_digit(char chr);

#endif