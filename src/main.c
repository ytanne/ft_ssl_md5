/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:19:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/25 15:59:38 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		get_flags(char **input_string, int arg_number)
{
	int		i;

	i = -1;
	while (++i < arg_number)
	{
		if (*input_string[i] == '-' && *(input_string[i] + 1))
		{
			if (*(input_string[i] + 1) == 'p')
				g_flags |= P_FLAG;
			else if (*(input_string[i] + 1) == 'q')
				g_flags |= Q_FLAG;
			else if (*(input_string[i] + 1) == 'r')
				g_flags |= R_FLAG;
			else if (*(input_string[i] + 1) == 's')
				g_flags |= S_FLAG;
			else
				unknown_option_error(input_string[i]);
		}
	}
	ft_printf("The flags are: %u\n", (unsigned char)g_flags);
}

static void		detect_hashing_function(char **input_str)
{
	int				i;

	i = 0;
	while (i <= 4 && ft_strcmp(g_hash_functions[i], input_str[0]) != 0)
		i++;
	if (i == 5)
		print_hash_error(input_str[0]);
	g_hash_ind = i;
}

static void		read_from_std_inp(void)
{
	ft_printf("On the maintanence\n");
}

static void		process_input(char **arguments, int arg_number)
{
	detect_hashing_function(arguments + 1);
	if (arg_number == 2)
		read_from_std_inp();
	else
		get_flags(arguments + 1, arg_number - 1);
	g_apply_hash_f[g_hash_ind](arguments);
}

int				main(int arg_number, char **arguments)
{
	if (arg_number == 1)
		print_usage();
	else
		process_input(arguments, arg_number);
	return (0);
}
