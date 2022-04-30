/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaramuk <mkaramuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:47:09 by mkaramuk          #+#    #+#             */
/*   Updated: 2022/04/29 18:17:42 by mkaramuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ftutils.h"
#include "argparser.h"

t_bool	check_args(int argc, char **argv)
{
	int	i;
	int	k;

	i = 0;
	while (++i < argc)
	{
		k = -1;
		while (argv[i][++k])
		{
			if (!is_digit(argv[i][k]))
				return (FT_FALSE);
		}
	}
	return (FT_TRUE);
}

int	*parse_args(int argc, char **argv)
{
	int	*args;
	int	i;

	if (!check_args(argc, argv))
		return (NULL);
	args = malloc(sizeof(int) * 5);
	args[0] = ft_atoi(argv[1]);
	args[1] = ft_atoi(argv[3]);
	args[2] = ft_atoi(argv[4]);
	args[3] = ft_atoi(argv[2]);
	args[4] = -1;
	if (argc > 5)
	{
		args[4] = ft_atoi(argv[5]);
		if (args[4] < 1)
			return (ft_free(args));
	}
	i = 0;
	while (i < 4)
		if (args[i++] < 1)
			return (ft_free(args));
	return (args);
}
