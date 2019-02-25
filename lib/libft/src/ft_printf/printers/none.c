/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   none.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:15:31 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:15:32 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"
#include "libft.h"

static size_t	print_padding(t_conv *conv, t_printf_buffer *buffer)
{
	unsigned int	i;

	i = 0;
	if (conv->field_width)
	{
		while (i < conv->field_width - 1)
		{
			if (conv->zero_padded && !conv->left_padded)
				add_to_buffer(buffer, '0');
			else
				add_to_buffer(buffer, ' ');
			++i;
		}
	}
	return (0);
}

int				printer_none(void *conv, va_list *vl, t_printf_buffer *buffer)
{
	(void)vl;
	if (!((t_conv *)conv)->left_padded)
		print_padding(conv, buffer);
	add_to_buffer(buffer, ((t_conv *)conv)->format->desc.desc);
	if (((t_conv *)conv)->left_padded)
		print_padding(conv, buffer);
	return (0);
}
