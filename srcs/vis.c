/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:16:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/25 19:29:24 by nlavrine         ###   ########.fr       */
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
			fdf->addr[pos] = 0x00bbff;
		else if (coord.prev_z > 8)
			fdf->addr[pos] = 0x0091ff;
		else if (coord.prev_z < 0)
			fdf->addr[pos] = 0x0033ff;
		else
			fdf->addr[pos] = color;
	}
}

void		bresenham_line(t_fdf *fdf, t_coords coord0, t_coords coord1, int color)
{
	t_coords	coord;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;

	coord.x = coord0.x;
	coord.y = coord0.y;
	coord.prev_z = coord0.prev_z;
	dx = abs(coord1.x - coord0.x);
	dy = -abs(coord1.y - coord0.y);
	sx = coord0.x < coord1.x ? 1 : -1;
	sy = coord0.y < coord1.y ? 1 : -1;
	error = dx + dy;
	while (1)
	{
		plot_pixel(fdf, coord, color);
		if ((coord.x == coord1.x || coord.x < 0) && (coord.y == coord1.y || coord.y < 0))
			break ;
		e2 = error + 1;
		if (e2 >= dy && coord.x != coord1.x)
		{
			error += dy;
			coord.x += sx;
		}
		if (e2 <= dx && coord.y != coord1.y)
		{
			error += dx;
			coord.y += sy;
		}
	}
}

void		vis_center(t_fdf *fdf)
{
	t_coords	coord0;
	t_coords	coord1;

	coord0.x = fdf->center.x;
	coord0.y = 0;
	coord0.z = 11;
	coord1.x = fdf->center.x;
	coord1.y = HEIGHT;
	bresenham_line(fdf, coord0, coord1, 0);
	coord0.x = 0;
	coord0.y = fdf->center.y;
	coord1.x = WIDTH;
	coord1.y = fdf->center.y;
	bresenham_line(fdf, coord0, coord1, 0);

}

void		tool_bar_frame(t_fdf *fdf)
{
	t_coords	coord0;
	t_coords	coord1;

	coord0.x = WIDTH - 200;
	coord0.y = 0;
	coord1.x = WIDTH - 200;
	coord1.y = 200;
	bresenham_line(fdf, coord0, coord1, 0);
	coord0.x = WIDTH - 200;
	coord0.y = 200;
	coord1.x = WIDTH;
	coord1.y = 200;
	bresenham_line(fdf, coord0, coord1, 0);
	
}

void		vis_map(t_fdf *fdf)
{
	int	x;
	int	y;
	int color;
	t_coords **coords;

	x = 0;
	y = 0;
	color = 0x2795a3;
	coords = fdf->coords;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				bresenham_line(fdf, coords[y][x],coords[y][x + 1], color);
			if (y != fdf->height - 1)
				bresenham_line(fdf, coords[y][x], coords[y + 1][x], color);
			x++;
		}
		y++;
	}
	tool_bar_frame(fdf);	
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 120, 10, 0x2795a3, "MENU");
}
