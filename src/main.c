/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:19:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/21 23:44:18 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	get_flags(char **inputString, int flags, int ptr)
{
	/*
	**	Trying to catch flags using bitwise comparison.
	**	I wanted to write if else statement to initialize the flags.
	*/
}

static void detectHashingFunction(char **inputString)
{
	int				i;

	i = 0;
	while (i <= 4 && ft_strcmp(hashFunctions[i], inputString[0]) != 0)
		i++;
	if (i == 5)
		printHashError(inputString[0]);
	get_flags(inputString + 1, FLAGS, i);
}

static void readFromStdInp(void)
{
	ft_printf("On the maintanence\n");
}

static void	processInput(char **arguments, int argumentsNumber)
{
	if (argumentsNumber == 2)
		readFromStdInp();
	else
		detectHashingFunction(arguments + 1);
}

int		main(int argumentsNumber, char **arguments)
{
	if (argumentsNumber == 1)
		printUsage();
	else
		processInput(arguments, argumentsNumber);
	return (0);
}
