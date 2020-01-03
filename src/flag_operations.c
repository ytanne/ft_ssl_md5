/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:27:01 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 13:44:48 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		flag_assignment(char flag, t_ssl_flags *ssl)
{
	if (flag == 'p')
		ssl->p++;
	else if (flag == 'q')
		ssl->q = 1;
	else if (flag == 'r')
		ssl->r = 1;
	else if (flag == 's')
	{
		ssl->s = 1;
		ft_printf("Bob, do something\n");
		return (0);
	}
	else
		illegal_option_error(flag);
	return (1);
}

void			get_flags(char **input, int limit, t_ssl_flags *ssl)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		if (input[i][0] == '-')
		{
			while (*(++input[i]))
				if (flag_assignment(*(input[i]), ssl) == 0)
					break ;
		}
		else
			return ;
	}
}

void			init_flags(t_ssl_flags **ssl)
{
	*ssl = (t_ssl_flags *)malloc(sizeof(t_ssl_flags));
	(*ssl)->p = 0;
	(*ssl)->q = 0;
	(*ssl)->s = 0;
}
