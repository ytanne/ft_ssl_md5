/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 23:59:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/12/31 17:30:35 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H
# include "libft.h"

typedef struct				s_md5
{
	uint32_t				a;
	uint32_t				b;
	uint32_t				c;
	uint32_t				d;
	uint32_t				f;
	uint32_t				words[16];
	int						g;
}							t_md5;

typedef unsigned long int	t_uint4;
void						ft_md5(char *string);
void						usage_print(void);
void						print_from_stdin(void);
uint32_t					f_function(uint32_t x, uint32_t y, uint32_t z);
uint32_t					g_function(uint32_t x, uint32_t y, uint32_t z);
uint32_t					h_function(uint32_t x, uint32_t y, uint32_t z);
uint32_t					i_function(uint32_t x, uint32_t y, uint32_t z);
uint32_t					leftrotate(uint32_t n, int c);

#endif
