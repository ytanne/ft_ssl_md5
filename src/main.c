/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:19:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/21 21:41:37 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void printUsage(void)
{
	ft_printf("This is not correct way to use the function, you coward bastard!\n");
}

static void	processInput(char **av, int ac)
{
	av[0] = "0";
	ac = 0;
}

int		main(int ac, char **av)
{
	if (ac == 1)
		printUsage();
	else
		processInput(av, ac);
	return (0);
}
