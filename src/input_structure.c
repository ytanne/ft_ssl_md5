/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 16:30:55 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 13:45:25 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_ssl_inputs			*new_ssl(char *string, int s)
{
	t_ssl_inputs		*new_data;

	new_data = (t_ssl_inputs *)malloc(sizeof(t_ssl_inputs));
	new_data->string = ft_strdup(string);
	new_data->s = s;
	new_data->next = NULL;
	return (new_data);
}

void					add_to_end(t_ssl_inputs *old, t_ssl_inputs *new)
{
	t_ssl_inputs		*tmp;

	if (!old)
		old = new;
	else
	{
		tmp = old;
		while (old->next)
			old = old->next;
		old->next = new;
	}
}

void					delete_ssl_input(t_ssl_inputs *ssl_input)
{
	t_ssl_inputs		*tmp_input;

	while (ssl_input)
	{
		tmp_input = ssl_input;
		ssl_input = ssl_input->next;
		ft_strdel(&(tmp_input->string));
		free(&tmp_input);
	}
}