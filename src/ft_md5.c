/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:18 by yorazaye          #+#    #+#             */
/*   Updated: 2019/12/31 17:06:38 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

int				g_s[64] =\
{\
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,\
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,\
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,\
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21\
};

uint32_t		g_k[64] =\
{\
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,\
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,\
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,\
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,\
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,\
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,\
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,\
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,\
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,\
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,\
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,\
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,\
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,\
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,\
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,\
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391\
};

uint32_t		g_abcd[4] =\
{\
	0x67452301,\
	0xefcdab89,\
	0x98badcfe,\
	0x10325476\
};

uint8_t		g_message[64] =\
{\
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,\
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0\
};

static void		fill_chunk(char *string)
{
	int		i;

	i = -1;
	while (++i < 56 && string[i])
		g_message[i] = (uint8_t)string[i];
	if (i < 56)
		g_message[i] = 128;
}

static void		declare_abcd(t_md5 *md5_data)
{
	md5_data->a = g_abcd[0];
	md5_data->b = g_abcd[1];
	md5_data->c = g_abcd[2];
	md5_data->d = g_abcd[3];
}

static void		append_length(uint64_t length)
{
	g_message[63] = (length & 0xFF00000000000000) >> 56;
	g_message[62] = (length & 0xFF000000000000) >> 48;
	g_message[61] = (length & 0xFF0000000000) >> 40;
	g_message[60] = (length & 0xFF00000000) >> 32;
	g_message[59] = (length & 0xFF000000) >> 24;
	g_message[58] = (length & 0xFF0000) >> 16;
	g_message[57] = (length & 0xFF00) >> 8;
	g_message[56] = (length & 0xFF);
}

static void		divide2words(uint32_t *words)
{
	int		i;
	int		k;

	i = 0;
	k = -1;
	words[0] = 0;
	while (++k < 16)
	{
		words[k] = ((uint32_t)g_message[i + 3] << 24) |\
		((uint32_t)g_message[i + 2] << 16) |\
		((uint32_t)g_message[i + 1] << 8) | \
		(uint32_t)g_message[i];
		i += 4;
	}
}

void			little_endian_print(uint32_t number)
{
	ft_printf("%02x", number & 0xFF);
	ft_printf("%02x", (number >> 8) & 0xFF);
	ft_printf("%02x", (number >> 16) & 0xFF);
	ft_printf("%02x", (number >> 24) & 0xFF);
}

void			ft_process_words(t_md5 *md5_data, int i)
{
	if (i >= 0 && i <= 15)
	{
		md5_data->f = f_function(md5_data->b, md5_data->c, md5_data->d);
		md5_data->g = i;
	}
	else if (i >= 16 && i <= 31)
	{
		md5_data->f = g_function(md5_data->b, md5_data->c, md5_data->d);
		md5_data->g = (5 * i + 1) % 16;
	}
	else if (i >= 32 && i <= 47)
	{
		md5_data->f = h_function(md5_data->b, md5_data->c, md5_data->d);
		md5_data->g = (3 * i + 5) % 16;
	}
	else if (i >= 48 && i <= 63)
	{
		md5_data->f = i_function(md5_data->b, md5_data->c, md5_data->d);
		md5_data->g = (7 * i) % 16;
	}
	md5_data->f += md5_data->a + g_k[i] + md5_data->words[md5_data->g];
	md5_data->a = md5_data->d;
	md5_data->d = md5_data->c;
	md5_data->c = md5_data->b;
	md5_data->b += leftrotate(md5_data->f, g_s[i]);
}

void			ft_md5(char *string)
{
	t_md5			*md5_data;
	int				i;

	md5_data = (t_md5 *)malloc(sizeof(t_md5));
	declare_abcd(md5_data);
	fill_chunk(string);
	append_length((uint64_t)(ft_strlen(string) * 8));
	divide2words((uint32_t *)md5_data->words);
	i = -1;
	while (++i < 64)
		ft_process_words(md5_data, i);
	g_abcd[0] += md5_data->a;
	g_abcd[1] += md5_data->b;
	g_abcd[2] += md5_data->c;
	g_abcd[3] += md5_data->d;
	ft_printf("MD5 (\"%s\") = ", string);
	i = -1;
	while (++i < 4)
		little_endian_print(g_abcd[i]);
}