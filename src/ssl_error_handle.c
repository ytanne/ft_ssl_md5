/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:41:52 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/22 23:20:52 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	printUsage(void)
{
	ft_printf("This is not correct way to use the function, you coward bastard!\n");
}

void	printHashError(char *errorHash)
{
	if (errorHash)
		ft_printf("ft_ssl:Error: '%s' is an invalid command.\n", errorHash);
	else
		return ;
}

/*
**	Need to figure the error handle
**	below
*/

void	unknownOptionError(char *errorHash)
{
	ft_printf("unknow option '%s'\n", errorHash);
	exit(0);
}
