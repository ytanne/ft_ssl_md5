/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 17:40:09 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/07 16:19:38 by yorazaye         ###   ########.fr       */
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

char 	*get_content_from_fd(int fd)
{
	char	*line;
	char	*result;
	char	*tmp;

	tmp = NULL;
	result = NULL;
	line = ft_strnew(12);
	while (read(fd, line, 10))
	{
		line[10] = '\0';
		ft_concat(&result, &tmp, line);
	}
	ft_strdel(&line);
	if (!result)
	{
		result = ft_strnew(1);
		result[0] = '\0';
	}
	return (result);
}

void	g_abcd_init(uint32_t *abcd)
{
	(abcd)[0] = 0x67452301;
	(abcd)[1] = 0xefcdab89;
	(abcd)[2] = 0x98badcfe;
	(abcd)[3] = 0x10325476;
}

/*
void	md5_512_division(char *string)
{
	 
}
*/
