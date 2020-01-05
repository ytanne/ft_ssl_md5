/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:44:34 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/05 12:48:20 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_md5.h"

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

void		invalid_command_error(char *command)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", command);
	ft_printf("\nStandard commands:\n\nMessage Digest commands:");
	ft_printf("\nmd5\nsha256\n\nCipher commands:");
	exit(1);
}

void		print_from_stdin(t_ssl *ssl)
{
	char	*line;
	char	*result;
	char	*tmp;

	tmp = NULL;
	result = NULL;
	line = ft_strnew(12);
	while (read(1, line, 10))
	{
		line[10] = '\0';
		ft_concat(&result, &tmp, line);
	}
	ft_strdel(&line);
	if (!result)
	{
		result = ft_strnew(1);
		result[0] = '\0';
	}
	g_ssl_functions[ssl->command](ssl, result);
	ft_strdel(&result);
}

void		little_endian_print(uint32_t number)
{
	ft_printf("%02x", number & 0xFF);
	ft_printf("%02x", (number >> 8) & 0xFF);
	ft_printf("%02x", (number >> 16) & 0xFF);
	ft_printf("%02x", (number >> 24) & 0xFF);
}
