/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:40:09 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 17:26:48 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_concat(char **result, char **tmp, char *line)
{
	if (!(*tmp))
		*result = ft_strdup(line);
	else
	{
		*result = ft_strjoin(*tmp, line);
		ft_strdel(tmp);
	}
	*tmp = *result;
}
