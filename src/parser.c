/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvignal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:10:34 by cvignal           #+#    #+#             */
/*   Updated: 2019/01/28 15:52:17 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "parser.h"

static int	add_coords(t_list **list, int i, char *line)
{
	char	**tab;
	int		j;
	t_coord	*point;
	t_list	*new;

	if (!(tab = ft_strsplit(line, " ")))
		return (0);
	j = 0;
	while (tab[j])
	{
		if (!(point = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		point->x = i;
		point->y = j;
		point->z = ft_atoi(tab[j]);
		if (!(new = ft_lstnew(point, sizeof(point))))
			return (0);
		ft_lstapp(list, new);
		j++;
		free(point);
	}
	return (1);
}

t_list	*fdf_parser(char *name)
{
	t_list	*points;
	int		fd;
	char	*line;
	int		i;

	points = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (!add_coords(&points, i, line))
			return (NULL);
		i++;
		free(line);
	}
	return (points);
}
