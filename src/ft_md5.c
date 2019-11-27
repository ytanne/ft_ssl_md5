/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 22:49:00 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/26 19:36:17 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void			append_message(char *message)
{
	int			i;
	int			l;

	i = -1;
	l = ft_strlen(message);
	ft_strncpy((char *)g_chunk, message, 64);
	g_chunk[l] = 0x80;
	while (l > 0)
		g_chunk[63 - --l] = message[++i];
}

static void			break_chunk(t_chart m_words[16][4])
{
	int				i;
	int				j;
	int				l;

	l = -1;
	j = -1;
	while (++l < 16)
	{
		i = -1;
		while (++i < 4)
			m_words[l][i] = g_chunk[++j];
	}
}

static void			init_hashes(t_uint4 hashes[4], t_uint4 xyz[3])
{
	hashes[0] = g_a0;
	hashes[1] = g_b0;
	hashes[2] = g_c0;
	hashes[3] = g_d0;
	xyz[0] = hashes[1];
	xyz[1] = hashes[2];
	xyz[2] = hashes[3];
}

void				ft_md5(char **objects)
{
	t_chart			m_words[16][4];
	t_uint4			hashes[4];
	t_uint4			xyz[3];
	int				i[2];
	t_uint4			F;

	append_message(objects[2]);
	break_chunk(m_words);
	init_hashes(hashes, xyz);
	i[0] = -1;
	while (++i[0] < 64)
	{
		if (i[0] >= 0 && i[0] <= 15)
		{
			F = auxilary_f(xyz);
			i[1] = i[0];
		}
		else if (i[0] >= 16 & i[0] <= 31)
		{
			F = auxilary_g(xyz);
			i[1] = (5 * i[0] + 1) % 16;
		}
		else if (i[0] >= 32 & i[0] <= 47)
		{
			F = auxilary_h(xyz);
			i[1] = (3 * i[0] + 5) % 16;
		}
		else if (i[0] >= 48 & i[0] <= 63)
		{
			F = auxilary_i(xyz);
			i[1] = (7 * i[0]) % 16;
		}
		F = F + hashes[0] + g_sine_t[i[0]] + g_chunk[i[0]];
		hashes[0] = hashes[3];
		hashes[3] = hashes[2];
		hashes[2] = hashes[1];
		hashes[1] = hashes[1] + (ROTATE_LEFT(F, g_shift[i[0]]));
	}
	g_a0 += hashes[0];
	g_b0 += hashes[1];
	g_c0 += hashes[2];
	g_d0 += hashes[3];
	ft_printf("%#x ", g_a0); 
	ft_printf("%#x ", g_b0); 
	ft_printf("%#x ", g_c0); 
	ft_printf("%#x\n", g_d0); 
	g_digest |= g_a0;
	ft_memcpy(g_digest, (char *)g_c0, 4);
	ft_memcpy(g_digest, (char *)g_d0, 4);
}
