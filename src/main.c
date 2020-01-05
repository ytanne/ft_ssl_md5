/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:12 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/05 12:48:42 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		process_flags_inputs(t_ssl *ssl)
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

void		detect_command(char *command, t_ssl *ssl)
{
	int		i;

	i = -1;
	while (++i < 2)
		if (ft_strcmp(command, g_ssl_commands[i]) == 0)
		{
			ssl->command = i;
			break ;
		}
	if (i >= 2)
		invalid_command_error(command);
}

void		input_processing(char **input, int input_number)
{
	t_ssl		*ssl;

	init_ssl(&ssl);
	detect_command(input[0], ssl);
	if (input_number == 1)
		print_from_stdin(ssl);
	else
	{
		get_flags(input + 1, --input_number, ssl);
		process_flags_inputs(ssl);
	}
}

int			main(int ac, char **av)
{
	av[0] = "";
	if (ac >= 2)
		input_processing(av + 1, ac - 1);
	else
		usage_print();
	return (0);
}
