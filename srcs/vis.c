/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:16:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/27 16:34:33 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		plot_pixel(t_fdf *fdf, t_coords coord, int color)
{
	int pos;

	pos = coord.x + coord.y * WIDTH;
	if (coord.x >= WIDTH - 200 && coord.y <= 200 && color)
		return ;
	if (coord.x >= 0 && coord.y >= 0 && pos < WIDTH * HEIGHT\
	&& coord.x < WIDTH && coord.y < HEIGHT)
	{
		if (coord.prev_z > 10)
			fdf->addr[pos] = 0x2C75FF;
		else if (coord.prev_z > 8)
			fdf->addr[pos] = 0xC0C0C0;
		else if (coord.prev_z < 0)
			fdf->addr[pos] = 0x2795a3;
		else
			fdf->addr[pos] = color;
	}
}

t_coords	calc_delta(t_coords coord0, t_coords coord1,
												t_coords *delta, t_coords *iter)
{
	t_coords coord;

	coord.x = coord0.x;
	coord.y = coord0.y;
	coord.prev_z = coord0.prev_z;
	delta->x = abs(coord1.x - coord0.x);
	delta->y = -abs(coord1.y - coord0.y);
	iter->x = coord0.x < coord1.x ? 1 : -1;
	iter->y = coord0.y < coord1.y ? 1 : -1;
	return (coord);
}

void		bresenham_line(t_fdf *fdf, t_coords coord0,
													t_coords coord1, int color)
{
	t_coords	coord;
	t_coords	delta;
	t_coords	iter;
	t_coords	error;

	coord = calc_delta(coord0, coord1, &delta, &iter);
	error.x = delta.x + delta.y;
	while (1)
	{
		plot_pixel(fdf, coord, color);
		if ((coord.x == coord1.x || coord.x < 0)\
						&& (coord.y == coord1.y || coord.y < 0))
			break ;
		error.y = error.x + 1;
		if (error.y >= delta.y && coord.x != coord1.x)
		{
			error.x += delta.y;
			coord.x += iter.x;
		}
		if (error.y <= delta.x && coord.y != coord1.y)
		{
			error.x += delta.x;
			coord.y += iter.y;
		}
	}
}

void		tool_bar_frame(t_fdf *fdf)
{
	t_coords	coord0;
	t_coords	coord1;

	coord0.x = WIDTH - 200;
	coord0.y = 0;
	coord0.prev_z = -1;
	coord1.x = WIDTH - 200;
	coord1.y = 200;
	bresenham_line(fdf, coord0, coord1, 0);
	coord0.x = WIDTH - 200;
	coord0.y = 200;
	coord1.x = WIDTH;
	coord1.y = 200;
	bresenham_line(fdf, coord0, coord1, 0);
	coord0.x = WIDTH - 180;
	coord0.y = 95;
	coord1.x = WIDTH - 175;
	coord1.y = 105;
	bresenham_line(fdf, coord0, coord1, 0);
	coord0.x = WIDTH - 170;
	coord0.y = 95;
	bresenham_line(fdf, coord0, coord1, 0);
}

void		vis_map(t_fdf *fdf)
{
	int			x;
	int			y;
	int			color;
	t_coords	**coords;

	y = 0;
	color = 0xCD853F;
	coords = fdf->coords;
	rerange_coords(fdf, fdf->coords, fdf->size);
	change_view(fdf, fdf->coords);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				bresenham_line(fdf, coords[y][x], coords[y][x + 1], color);
			if (y != fdf->height - 1)
				bresenham_line(fdf, coords[y][x], coords[y + 1][x], color);
			x++;
		}
		y++;
	}
	tool_bar_frame(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}
