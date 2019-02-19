/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:10:34 by cvignal           #+#    #+#             */
/*   Updated: 2019/02/19 11:01:19 by cvignal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft.h"
#include "parser.h"

static int	fill_line(t_map *map, int i, t_list *elt)
{
	char	**tab;
	int		j;

	if (!(tab = ft_strsplit(elt->content, " ")))
		return (1);
	if (!i)
		map->y_max = ft_tablen(tab);
	else if (ft_tablen(tab) != map->y_max)
		return (1);
	if (!(map->points[i] = (int*)malloc(sizeof(int) * ft_tablen(tab))))
		return (1);
	j = 0;
	while (tab[j])
	{
		map->points[i][j] = ft_atoi(tab[j]);
		j++;
	}
	ft_deltab(&tab);
	return (0);
}

static int	fill_points(t_map *map, t_list *list)
{
	int		i;
	t_list	*curr;

	if (!list)
		return (1);
	if (fill_line(map, 0, list))
		return (1);
	i = 1;
	curr = list->next;
	while (curr)
	{
		if (fill_line(map, i, curr))
			return (1);
		i++;
		curr = curr->next;
	}
	ft_lstdel(&list, &ft_delelt);
	return (0);
}

t_map		*fdf_parser(char *file_name)
{
	int		fd;
	t_list	*list;
	char	*line;
	t_list	*new;
	t_map	*ret;

	list = NULL;
	if ((fd = open(file_name, O_RDONLY | O_NOFOLLOW)) == -1)
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
	if (fill_points(ret, list))
		return (NULL);
	return (ret);
}
