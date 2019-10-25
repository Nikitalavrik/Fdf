/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:53 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/25 17:35:50 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		check_file(int	fd)
{
	char	*line;
	int		size;

	line = NULL;
	size = 0;
	while (get_next_line(fd, &line) == 1)
	{
		ft_memdel((void **)&line);
		size++;
	}
	ft_memdel((void **)&line);
	close(fd);
	return (size);
}

t_coords		**put_coords(t_coords **coords, char **splited, int y, int size)
{
	int			x;

	x = 0;
	while (x < size)
	{
		coords[y][x].x = x;
		coords[y][x].y = y;
		coords[y][x].z = ft_atoi(splited[x]);
		coords[y][x].prev_z = coords[y][x].z;
		x++;
	}
	free_splited(splited, size);
	return (coords);
}

t_coords	**check_lines(int fd, int size, int	*in_line)
{
	char		*line;
	char		**splited;
	t_coords	**coords;
	int			coords_in_line;
	int			i;

	line = NULL;
	*in_line = 0;
	i = 0;
	coords = ft_memalloc(sizeof(t_coords *) * (size + 1));
	while (get_next_line(fd, &line) == 1)
	{
		splited = ft_strsplit(line, ' ');
		if (!*in_line)
		{
			*in_line = split_len(splited);
			if (!*in_line)
				print_error("Map validation failed\n");
		}
		coords_in_line = split_len(splited);
		if (coords_in_line != *in_line)
			print_error("Map validation failed\n");
		coords[i] = ft_memalloc(sizeof(t_coords) * (*in_line + 1));
		coords = put_coords(coords, splited, i, *in_line);
		ft_memdel((void **)&line);
		i++;
	}
	ft_memdel((void **)&line);
	return (coords);
}

t_coords	**parse_file(t_coords *size, char *filename)
{
	int			fd;
	t_coords 	**coords;

	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error("Something wrong with file\n");
	size->y = check_file(fd);
	if ((fd = open(filename, O_RDONLY)) == -1)
		print_error("Something wrong with file\n");
	coords = check_lines(fd, size->y, &size->x);
	return (coords);
}
