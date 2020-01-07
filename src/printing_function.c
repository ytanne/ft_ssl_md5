/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:33:32 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/06 21:29:18 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int			ssl_p_flag_print(uint32_t *abcd, char *string)
{
	int		i;

	i = 0;
	ft_printf("%s", string);
	while (i < 4)
		little_endian_print(abcd[i++]);
	ft_putchar('\n');
	return (1);
}

static int			ssl_q_flag_print(uint32_t *abcd)
{
	int		i;

	i = 0;
	while (i < 4)
		little_endian_print(abcd[i++]);
	ft_putchar('\n');
	return (1);
}

static int			ssl_r_flag_print(char *string, uint32_t *abcd)
{
	int		i;

	i = 0;
	while (i < 4)
		little_endian_print(abcd[i++]);
	ft_printf(" \"%s\"\n", string);
	return (1);
}

static int			ssl_s_flag_print(t_ssl *ssl, char *string, uint32_t *abcd)
{
	int		i;

	i = 0;
	if (ssl->s == 1)
		ft_printf("MD5 (\"%s\") = ", string);
	else
		ft_printf("MD5 (%s) = ", string);
	while (i < 4)
		little_endian_print(abcd[i++]);
	ft_putchar('\n');
	return (1);
}

void				hash_to_stdout(t_ssl *ssl, char *string, uint32_t *abcd)
{
	if (ssl->p >= 1)
		if (ssl_p_flag_print(abcd, string) == 1)
			return ;
	if (ssl->q == 1)
		if (ssl_q_flag_print(abcd) == 1)
			return ;
	if (ssl->r == 1)
		if (ssl_r_flag_print(string, abcd) == 1)
			return ;
	ssl_s_flag_print(ssl, string, abcd);
}
