/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:14:45 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:14:46 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_l(t_conv *conv)
{
	if (conv->type_mod == TYPE_MOD_L)
		conv->type_mod = TYPE_MOD_LL;
	else if (conv->type_mod == TYPE_MOD_NONE)
		conv->type_mod = TYPE_MOD_L;
	else if (conv->type_mod == TYPE_MOD_H)
		conv->type_mod = TYPE_MOD_NONE;
	else if (conv->type_mod == TYPE_MOD_HH)
		conv->type_mod = TYPE_MOD_H;
	else
		return (1);
	return (0);
}
