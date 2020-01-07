/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:58:17 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/07 09:22:00 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		p_flag(t_ssl *ssl)
{
	int		fl;

	fl = 0;
	while (ssl->p >= 1)
	{
		if (fl == 0)
		{
			print_from_stdin(ssl);
			fl = 1;
		}
		else
			ft_md5(ssl, "");
		--ssl->p;
	}
}

void		s_flag(t_ssl *ssl)
{
	while (ssl->inputs && ssl->inputs->s == 1)
	{
		g_ssl_functions[ssl->command](ssl, ssl->inputs->string);
		ssl->inputs = ssl->inputs->next;
	}
}

void		file_handling(t_ssl *ssl)
{
	ssl->s = 0;
	/*
	char	*document;

	while (ssl->inputs && ssl->inputs->s == 0)
	{
		g_ssl_functions[ssl->command](ssl, ssl->inputs->string);
		ssl->inputs = ssl->inputs->next;
	}
	*/
	ft_printf("Reading a file\n");
}
