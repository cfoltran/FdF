/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:08:31 by cvignal           #+#    #+#             */
/*   Updated: 2019/01/28 15:41:49 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "libft.h"

typedef struct	s_coord
{
	int	x;
	int	y;
	int	z;
}				t_coord;

t_list	*fdf_parser(char *name);

#endif
