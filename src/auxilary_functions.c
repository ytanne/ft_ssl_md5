/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:20:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/24 22:59:33 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_uint	auxilary_f(t_uint *xyz)
{
	return ((xyz[0] & xyz[1]) | (~xyz[0] & xyz[2]));
}

t_uint	auxilary_g(t_uint *xyz)
{
	return ((xyz[0] & xyz[2]) | (xyz[1] & ~xyz[2]));
}

t_uint	auxilary_h(t_uint *xyz)
{
	return ((xyz[0] ^ xyz[1] ^ xyz[2]));
}

t_uint	auxilary_i(t_uint *xyz)
{
	return (xyz[1] ^ (xyz[0] | ~xyz[2]));
}
