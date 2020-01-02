/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:44:34 by yorazaye          #+#    #+#             */
/*   Updated: 2019/12/31 17:12:18 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

void		usage_print(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}

void		print_from_stdin(void)
{
	char	*line;
	while (get_next_line(1, &line))
	{
		ft_printf("%s\n", line);
		ft_memdel((void**)&line);
	}
}