/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 13:27:01 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/06 15:25:54 by yorazaye         ###   ########.fr       */
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
		if (*(flag + 1))
		{
			add_to_end(&(ssl->inputs), new_input(flag + 1, 1));
			return (ft_strlen(flag + 1));
		}
		else
			return (0);
	}
	else
		illegal_option_error(*flag);
	return (1);
}

int			process_flag(char **input, int limit, t_ssl *ssl, int i)
{
	int		c;

	c = 0;
	while (*(++input[i]))
	{
		c = flag_assignment(input[i], ssl);
		if (c == 0)
		{
			if (i + 1 < limit)
				add_to_end(&(ssl->inputs), new_input(input[++i], 1));
			else
				argument_error();
			break ;
		}
		input[i] += c;
	}
	return (i);
}

int			get_flags(char **input, int limit, t_ssl *ssl)
{
	int		i;
	int		file_flag;
	
	i = 0;
	file_flag = 0;
	while (i < limit)
	{
		if (input[i][0] == '-' && file_flag == 0)
			i = process_flag(input, limit, ssl, i);
		else
		{
			add_to_end(&(ssl->inputs), new_input(input[++i], 0));
			file_flag = 1;
		}
		i++;
	}
	return (i);
}

void			init_ssl(t_ssl **ssl)
{
	*ssl = (t_ssl *)malloc(sizeof(t_ssl));
	(*ssl)->p = 0;
	(*ssl)->q = 0;
	(*ssl)->r = 0;
	(*ssl)->s = 0;
	(*ssl)->command = -1;
	(*ssl)->inputs = NULL;
}
