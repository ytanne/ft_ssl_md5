/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl_error_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:41:52 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/23 16:20:28 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	print_usage(void)
{
	ft_printf("This is not correct way to use the function!\n");
	exit(0);
}

void	print_hash_error(char *error_hash)
{
	if (error_hash)
	{
		ft_printf("ft_ssl:Error: '%s' is an invalid command.\n", error_hash);
		exit(0);
	}
	else
		return ;
}

/*
**	Need to figure the error handle
**	below
*/

void	unknown_option_error(char *error_hash)
{
	ft_printf("unknow option '%s'\n", error_hash);
	exit(0);
}
