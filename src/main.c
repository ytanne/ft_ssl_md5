/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:19:17 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/23 13:14:59 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void	get_flags(char **inputString, int argumentsNumber)
{
	int		i;

	i = -1;
	while (++i < argumentsNumber)
	{
		if (*inputString[i] == '-' && *(inputString[i] + 1))
		{
			if (*(inputString[i] + 1) == 'p')
				FLAGS |= P_FLAG;
			else if (*(inputString[i] + 1) == 'q')
				FLAGS |= Q_FLAG;
			else if (*(inputString[i] + 1) == 'r')
				FLAGS |= R_FLAG;
			else if (*(inputString[i] + 1) == 's')
				FLAGS |= S_FLAG;
			else
				unknownOptionError(inputString[i]);
		}
	}
	ft_printf("The flags are: %u\n", (unsigned char)FLAGS);
}

static void detectHashingFunction(char **inputString, int argumentsNumber)
{
	int				i;

	i = 0;
	while (i <= 4 && ft_strcmp(hashFunctions[i], inputString[0]) != 0)
		i++;
	if (i == 5)
		printHashError(inputString[0]);
	HASH_IND = i;
}

static void readFromStdInp(void)
{
	ft_printf("On the maintanence\n");
}

static void	processInput(char **arguments, int argumentsNumber)
{
	detectHashingFunction(arguments + 1, argumentsNumber - 1);
	if (argumentsNumber == 2)
		readFromStdInp();
	else
		get_flags(inputString + 1, argumentsNumber - 1);
	g_applyHashFunction[HASH_IND](inputString);
}

int		main(int argumentsNumber, char **arguments)
{
	if (argumentsNumber == 1)
		printUsage();
	else
		processInput(arguments, argumentsNumber);
	return (0);
}
