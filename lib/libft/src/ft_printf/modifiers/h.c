/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:14:39 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:14:40 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_h(t_conv *conv)
{
	if (conv->type_mod == TYPE_MOD_H)
		conv->type_mod = TYPE_MOD_HH;
	else if (conv->type_mod == TYPE_MOD_NONE)
		conv->type_mod = TYPE_MOD_H;
	else if (conv->type_mod == TYPE_MOD_L)
		conv->type_mod = TYPE_MOD_NONE;
	else if (conv->type_mod == TYPE_MOD_LL)
		conv->type_mod = TYPE_MOD_L;
	else
		return (1);
	return (0);
}
