/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:10:42 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/02 15:08:32 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

#include "ft_md5.h"

typedef struct      	s_ssl
{
    int             	command;
}                   	t_ssl;

typedef struct			s_ssl_flags
{
	int					p;
	int					q;
	int					r;
}						t_ssl_flags;

typedef struct			s_ssl_inputs
{
    char				*string;
	int					fd;
	int					s;
	struct s_ssl_inputs	*next;
}						t_ssl_inputs;


typedef void			t_ssl_function(char *string);
void					ft_md5(char *string);

static t_ssl_function	*g_ssl_functions[] =
{
	ft_md5
};

#endif