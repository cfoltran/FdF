/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:10:34 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/04 16:03:32 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "parser.h"

static int	fill_points(t_map *map, t_list *list)
{
	int		i;
	int		j;
	char	**tab;
	t_list	*curr;

	curr = list;
	i = 0;
	while (curr)
	{
		if (!(tab = ft_strsplit(curr->content, " ")))
			return (0);
		map->y_max = ft_tablen(tab);
		if (!(map->points[i] = (int*)malloc(sizeof(int) * map->y_max)))
			return (0);
		j = 0;
		while (tab[j])
		{
			map->points[i][j] = ft_atoi(tab[j]);
			j++;
		}
		ft_deltab(&tab);
		i++;
		curr = curr->next;
	}
	return (1);
}

t_map		*fdf_parser(char *file_name)
{
	int		fd;
	t_list	*list;
	char	*line;
	t_list	*new;
	t_map	*ret;

	list = NULL;
	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if (!(new = ft_lstnew(line, ft_strlen(line) + 1)))
			return (NULL);
		ft_lstapp(&list, new);
		free(line);
	}
	if (!(ret = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ret->x_max = ft_lstlen(list);
	ret->y_max = 0;
	if (!(ret->points = (int**)malloc(sizeof(int*) * ret->x_max)))
		return (NULL);
	if (!fill_points(ret, list))
		return (NULL);
	return (ret);
}
