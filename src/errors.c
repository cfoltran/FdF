/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:56:51 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/21 19:45:34 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int code)
{
	if (code == USG)
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	if (code == MEM)
		ft_putendl("Error : failed to allocate memory");
	if (code == ARG)
		ft_putendl("Error : invalid argument");
	if (code == MLX)
		ft_putendl("Error : mlx");
	exit(1);
}
