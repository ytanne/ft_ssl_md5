/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:20:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/23 15:51:22 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned int	auxilary_f(unsigned int *xyz)
{
	return ((xyz[0] & xyz[1]) | (~xyz[0] & xyz[2]));
}

unsigned int	auxilary_g(unsigned int *xyz)
{
	return ((xyz[0] & xyz[2]) | (xyz[1] & ~xyz[2]));
}

unsigned int	auxilary_h(unsigned int *xyz)
{
	return ((xyz[0] ^ xyz[1] ^ xyz[2]));
}

unsigned int	auxilary_i(unsigned int *xyz)
{
	return (xyz[1] ^ (xyz[0] | ~xyz[2]));
}
