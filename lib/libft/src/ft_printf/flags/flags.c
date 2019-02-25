/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:14:13 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:14:13 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_flag	g_flags[] =\
{
	{ FLAG_ALTERNATE, &flag_alternate },
	{ FLAG_ZERO, &flag_zero },
	{ FLAG_MINUS, &flag_minus },
	{ FLAG_PLUS, &flag_plus },
	{ FLAG_SPACE, &flag_space }
};

t_flag_op	get_flag_op(char c)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(g_flags) / sizeof(*g_flags))
	{
		if (g_flags[i].desc == c)
			return (g_flags[i].flag_op);
		++i;
	}
	return (NULL);
}
