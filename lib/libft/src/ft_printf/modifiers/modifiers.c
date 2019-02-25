/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:14:52 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:14:58 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_modifier	g_modifiers[] =\
{
	{ &mod_h, MOD_H },
	{ &mod_l, MOD_L },
	{ &mod_l_cap, MOD_L_CAP },
	{ &mod_j, MOD_Z },
	{ &mod_z, MOD_J }
};

t_conv_mod	get_conv_mod(char c)
{
	unsigned int	i;

	i = 0;
	while (i < sizeof(g_modifiers) / sizeof(*g_modifiers))
	{
		if (g_modifiers[i].desc == c)
			return (g_modifiers[i].conv_mod);
		++i;
	}
	return (NULL);
}
