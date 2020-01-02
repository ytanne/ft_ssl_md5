/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:12 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/02 15:03:40 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*g_ssl_commands[2] =\
{\
	"md5",
	"sha256"
};

void		detect_command(char *command, t_ssl *ssl)
{
	int		i;

	i = -1;
	while (++i < 2)
		if (ft_strcmp(command, g_ssl_commands[i]) == 0 && (ssl->command = i))
			break;
	if (ssl->command == i)
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", command);
		ft_printf("\nStandard commands:\n\nMessage Digest commands:");
		ft_printf("\nmd5\nsha256\n\nCipher commands:");
		exit(1);
	}
}

void		input_processing(char **input, int input_number)
{
	t_ssl	*ssl;

	ssl = (t_ssl *)malloc(sizeof(t_ssl));
	detect_command(input[0], ssl);
	if (input_number == 1)
		print_from_stdin();
	else
	{
		capture_the_flag(input + 1, --input_number);
		ft_printf("Hello");
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
