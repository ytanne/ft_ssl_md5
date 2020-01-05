/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:27:01 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/04 18:07:09 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		flag_assignment(char *flag, t_ssl *ssl)
{
	if (*flag == 'p')
		ssl->p++;
	else if (*flag == 'q')
		ssl->q = 1;
	else if (*flag == 'r')
		ssl->r = 1;
	else if (*flag == 's')
	{
		ssl->s = 1;
		if (flag + 1)
			add_to_end(&ssl->inputs, new_input(flag + 1, 1));
		return (0);
	}
	else
		illegal_option_error(*flag);
	return (1);
}

void			get_flags(char **input, int limit, t_ssl *ssl)
{
	int		i;

	i = 0;
	while (i < limit)
	{
		if (input[i][0] == '-')
		{
			while (*(++input[i]))
				if (flag_assignment(input[i], ssl) == 0)
					break ;
		}
		else
			return ;
		i++;
	}
}

void			init_ssl(t_ssl **ssl)
{
	*ssl = (t_ssl *)malloc(sizeof(t_ssl));
	(*ssl)->p = 0;
	(*ssl)->q = 0;
	(*ssl)->r = 0;
	(*ssl)->s = 0;
	(*ssl)->command = -1;
}
