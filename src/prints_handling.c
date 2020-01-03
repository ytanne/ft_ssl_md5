/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:44:34 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 13:47:22 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		usage_print(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void		illegal_option_error(char option)
{
	ft_printf("md5: illegal option -- %c\n", option);
	ft_printf("usage: ft_ssl command [-pqr] [-s string] [files ...]\n");
	exit(1);
}

void		print_from_stdin(t_ssl *ssl)
{
	char	*line;
	char	*result;
	char	*tmp;

	tmp = NULL;
	while (get_next_line(1, &line))
	{
		if (!tmp)
			result = ft_strdup(line);
		else
		{
			result = ft_strjoin(tmp, "\n");
			ft_strdel(&tmp);
			tmp = result;
			result = ft_strjoin(tmp, line);
			ft_strdel(&tmp);
		}
		tmp = result;
		ft_strdel(&line);
	}
	g_ssl_functions[ssl->command](result);
	ft_strdel(&result);
}
