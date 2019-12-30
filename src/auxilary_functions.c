/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 22:17:46 by yorazaye          #+#    #+#             */
/*   Updated: 2019/12/30 00:53:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

uint32_t	leftrotate(uint32_t n, int c)
{
	return (n << c | n >> (32 - c));
}

uint32_t	f_function(uint32_t x, uint32_t y, uint32_t z)
{
	return (((x & y) | (~(x) & z)) % UINT32_MAX);
}

uint32_t	g_function(uint32_t x, uint32_t y, uint32_t z)
{
	return (((z & x) | (~(z) & y)) % UINT32_MAX);
}

uint32_t	h_function(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x ^ y ^ z) % UINT32_MAX);
}

uint32_t	i_function(uint32_t x, uint32_t y, uint32_t z)
{
	return ((y ^ (x | ~(z))) % UINT32_MAX);
}
