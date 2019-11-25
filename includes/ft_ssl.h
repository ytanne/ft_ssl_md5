/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:22:31 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/24 23:00:49 by yorazaye         ###   ########.fr       */
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

typedef unsigned long int	t_uint4;
typedef unsigned int		t_uint;

static t_uint				g_shift[64] =
{
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static t_uint4				g_sine_t[64] =
{
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static t_uint				g_flags;
static t_uint				g_hash_ind;
static t_uint4				g_word;

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

t_uint						auxilary_f(t_uint *xyz);
t_uint						auxilary_g(t_uint *xyz);
t_uint						auxilary_h(t_uint *xyz);
t_uint						auxilary_i(t_uint *xyz);

#endif
