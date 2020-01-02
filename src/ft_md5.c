/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:18 by yorazaye          #+#    #+#             */
/*   Updated: 2020/01/02 13:46:20 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_md5.h"

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