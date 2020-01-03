/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:10:42 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/03 13:35:52 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"

typedef struct			s_ssl
{
	int					command;
}						t_ssl;

typedef struct			s_ssl_flags
{
	int					p;
	int					q;
	int					r;
	int					s;
}						t_ssl_flags;

typedef struct			s_ssl_inputs
{
	char				*string;
	int					s;
	struct s_ssl_inputs	*next;
}						t_ssl_inputs;


typedef void			t_ssl_function(char *string);
void					ft_md5(char *string);
void					illegal_option_error(char option);
void					usage_print(void);
void					print_from_stdin(t_ssl *ssl);
t_ssl_inputs			*new_ssl(char *string, int s);
void					add_to_end(t_ssl_inputs *old, t_ssl_inputs *new);
char					*ft_concat(char *line, char *extra, int size);
void					get_flags(char **inp, int len, t_ssl_flags *ssl);
void					init_flags(t_ssl_flags **ssl);

static t_ssl_function	*g_ssl_functions[] =
{
	ft_md5
};

#endif
