/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:08:31 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/04 11:21:12 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

typedef struct	s_map
{
	int	**points;
	int	x_max;
	int	y_max;
}				t_map;

t_map			*fdf_parser(char *file_name);

#endif
