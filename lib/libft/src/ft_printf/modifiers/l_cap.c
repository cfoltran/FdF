/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:14:49 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:14:51 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	mod_l_cap(t_conv *conv)
{
	if (conv->type_mod == TYPE_MOD_NONE)
		conv->type_mod = TYPE_MOD_L_CAP;
	else
		return (1);
	return (0);
}
