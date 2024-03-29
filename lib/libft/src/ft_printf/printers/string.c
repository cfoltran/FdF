/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:15:36 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:15:37 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_printf.h"

static int	print_space(t_conv *conv, size_t len, t_printf_buffer *buffer)
{
	int	i;

	i = 0;
	while (len + i < conv->field_width)
	{
		if (conv->zero_padded && !conv->left_padded)
			add_to_buffer(buffer, '0');
		else
			add_to_buffer(buffer, ' ');
		++i;
	}
	return (i);
}

int			printer_string(void *conv, va_list *vl, t_printf_buffer *buffer)
{
	size_t	len;
	char	*arg;

	arg = va_arg((*vl), char *);
	if (((t_conv *)conv)->precision_set)
	{
		if (arg)
			len = ft_llmin(ft_strlen(arg), ((t_conv *)conv)->precision);
		else
			len = ft_llmin(ft_strlen(NULL_PRINT), ((t_conv *)conv)->precision);
	}
	else
		len = ft_strlen(arg ? arg : NULL_PRINT);
	if (!((t_conv *)conv)->left_padded)
		print_space(conv, len, buffer);
	add_to_buffer_nstring(buffer, arg ? arg : NULL_PRINT, len);
	if (((t_conv *)conv)->left_padded)
		print_space(conv, len, buffer);
	return (0);
}
