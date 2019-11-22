/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:22:31 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/21 23:41:39 by yorazaye         ###   ########.fr       */
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
# define R_FLAG 2
# define S_FLAG 2


static unsigned int FLAGS : 4;

static char					*hashFunctions[10] =
{
	"md5",
	"sha256",
	"sha512",
	"whirlpool"
};

typedef void				t_hashFunctionPtr(char **flagsAndObjects);

void						ft_md5(char **flagsAndObjects);
void						ft_sha256(char **flagsAndObjects);
void						ft_sha512(char **flagsAndObjects);
void						ft_whirlpool(char **flagsAndObjects);

static t_hashFunctionPtr	*g_hash_table[] =
{
	ft_md5,
	ft_sha256,
	ft_sha512,
	ft_whirlpool
};

void						printHashError(char *errorHash);
void						printUsage(void);

#endif
