/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 23:10:42 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/04 10:19:46 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_md5.h"

static char				*g_ssl_commands[2] =\
{\
	"md5",
	"sha256"
};

typedef struct			s_ssl_inputs
{
	char				*string;
	int					s;
	struct s_ssl_inputs	*next;
}						t_ssl_inputs;

typedef struct			s_ssl
{
	int					p;
	int					q;
	int					r;
	int					s;
	int					command;
	t_ssl_inputs		*inputs;
}						t_ssl;

typedef void			t_ssl_function(char *string);
void					ft_md5(char *string);
void					illegal_option_error(char option);
void					invalid_command_error(char *command);
void					usage_print(void);
void					print_from_stdin(t_ssl *ssl);
t_ssl_inputs			*new_input(char *string, int s);
void					add_to_end(t_ssl_inputs **old, t_ssl_inputs *new);
void					ft_concat(char **dest, char **temp, char *src);
void					get_flags(char **inp, int len, t_ssl *ssl);
void					init_ssl(t_ssl **ssl);

static t_ssl_function	*g_ssl_functions[] =
{
	ft_md5
};

#endif
