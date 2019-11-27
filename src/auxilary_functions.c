/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:20:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/26 18:50:45 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_uint4	auxilary_f(t_uint4 xyz[3])
{
	return ((xyz[0] & xyz[1]) | (~xyz[0] & xyz[2]));
}

t_uint4	auxilary_g(t_uint4 xyz[3])
{
	return ((xyz[0] & xyz[2]) | (xyz[1] & ~xyz[2]));
}

t_uint4	auxilary_h(t_uint4 xyz[3])
{
	return ((xyz[0] ^ xyz[1] ^ xyz[2]));
}

t_uint4	auxilary_i(t_uint4 xyz[3])
{
	return (xyz[1] ^ (xyz[0] | ~xyz[2]));
}
