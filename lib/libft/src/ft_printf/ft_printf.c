/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:13:33 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:13:34 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			vl;
	int				pos;
	t_printf_buffer	*buffer;
	int				ret;

	if (!format || !(buffer = create_buffer()))
		return (-1);
	pos = 0;
	ret = 0;
	va_start(vl, format);
	while (format[pos])
	{
		if (format[pos] == CONV_START)
		{
			if ((ret = print_conv(format, &pos, &vl, buffer)))
			{
				free_buffer(buffer);
				break ;
			}
		}
		else
			print_normal(format, &pos, buffer);
	}
	va_end(vl);
	return (ret ? -1 : (int)dump_buffer(1, buffer));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list			vl;
	int				pos;
	t_printf_buffer	*buffer;
	int				ret;

	if (!format || !(buffer = create_buffer()))
		return (-1);
	pos = 0;
	ret = 0;
	va_start(vl, format);
	while (format[pos])
	{
		if (format[pos] == CONV_START)
		{
			if ((ret = print_conv(format, &pos, &vl, buffer)))
			{
				free_buffer(buffer);
				break ;
			}
		}
		else
			print_normal(format, &pos, buffer);
	}
	va_end(vl);
	return (ret ? -1 : (int)dump_buffer(fd, buffer));
}
