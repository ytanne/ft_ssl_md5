/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:12 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/06 15:29:52 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		process_flags_inputs(t_ssl *ssl, char **inputs)
{
	int		fl;

	fl = 0;
	*inputs = 0;
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
		get_flags(input + 1, input_number - 1, ssl);
		while (ssl->inputs)
		{
			ft_printf("%s and %d\n", ssl->inputs->string, ssl->inputs->s);
			ssl->inputs = ssl->inputs->next;
		}
		//process_flags_inputs(ssl, input);
	}
	delete_ssl_input(&(ssl->inputs));
	ft_memdel((void **)&ssl);
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
