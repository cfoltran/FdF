/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:56:51 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/25 10:32:44 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	errors(int code)
{
	if (code == MEM)
		ft_dprintf(2, "Error : failed to allocate memory\n");
	if (code == ARG)
		ft_dprintf(2, "Error : invalid map\n");
	if (code == MLX)
		ft_dprintf(2, "Error : mlx\n");
	return (1);
}
