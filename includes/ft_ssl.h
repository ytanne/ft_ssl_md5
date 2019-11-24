/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:22:31 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/23 16:18:34 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"

/*
**	Hash flags in binary
**	-p -----> 1
**	-q -----> 2
**	-r -----> 4
**	-s -----> 8
*/

# define P_FLAG 1
# define Q_FLAG 2
# define R_FLAG 4
# define S_FLAG 8

static unsigned int			g_flags;
static unsigned int			g_hash_ind;
static unsigned long int	g_word;

static char					*g_hash_functions[10] =
{
	"md5",
	"sha256",
	"sha512",
	"whirlpool"
};

typedef void				t_hash_ptr(char **flags_objects);

void						ft_md5(char **flags_objects);
void						ft_sha256(char **flags_objects);
void						ft_sha512(char **flags_objects);
void						ft_whirlpool(char **flags_objects);

static t_hash_ptr	*g_apply_hash_f[] =
{
	ft_md5,
	ft_sha256,
	ft_sha512,
	ft_whirlpool
};

void						print_hash_error(char *error_hash);
void						print_usage(void);
void						unknown_option_error(char *error_hash);

/*
**	Auxilary functions F, G, H, I
*/

unsigned int				auxilary_f(unsigned int *xyz);
unsigned int				auxilary_g(unsigned int *xyz);
unsigned int				auxilary_h(unsigned int *xyz);
unsigned int				auxilary_i(unsigned int *xyz);

#endif
