/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putullnbr_base_buffer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 11:13:49 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/25 11:13:50 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static size_t	get_nbr_size_base(unsigned long long nb,
		unsigned long long base)
{
	size_t	size;

	size = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= base;
		++size;
	}
	return (size);
}

size_t			ft_putullnbr_base_buffer(unsigned long long nb,
		const char *base, t_printf_buffer *buffer)
{
	size_t				size;
	size_t				base_len;
	unsigned long long	pow;

	base_len = ft_strlen(base);
	size = get_nbr_size_base(nb, base_len);
	while (size--)
	{
		pow = ft_ullpow(base_len, size);
		add_to_buffer(buffer, *(base + nb / pow));
		nb %= pow;
	}
	return (0);
}
