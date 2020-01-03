/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:40:09 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 13:45:57 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*ft_concat(char *line, char *extra, int size)
{
	char	*result;
	int		i;

	i = ft_strlen(line);
	result = ft_strnew(size);
	result = ft_strdup(line);
	ft_strncpy(result + i, extra, 42);
	result[size] = '\0';
	return (result);
}
