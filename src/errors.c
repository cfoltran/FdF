/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:56:51 by clfoltra          #+#    #+#             */
/*   Updated: 2019/02/18 13:32:02 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int code)
{
	if (code == 1)
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
	if (code == 2)
		ft_putendl("Erreur : failed to allocate memory");
	if (code == 3)
		ft_putendl("Erreur : invalid argument");
	exit(1);
}
