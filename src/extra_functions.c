/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 22:16:03 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/24 23:02:25 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_pow(int base, int power)
{
	long long int		result;

	result = 1;
	while (power-- > 0)
		result *= base;
	return (result);
}

unsigned int		ft_abs(int number)
{
	return (number >= 0) ? number : -1 * number;
}
