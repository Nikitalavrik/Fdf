/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:16:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 17:37:52 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

// int			abs(int	num)
// {
// 	return (num > 0 ? num : -num)
// }

void		plot_pixel(t_fdf *fdf, int x, int y, int color)
{
	int pos;

	pos = x + y * WIDTH;
	if (x >= 0 && y >= 0 && pos < WIDTH * HEIGHT)
	{
		fdf->addr[pos] = color;
	}
		
}

void		bresenham_line(t_fdf *fdf, t_coords coord0, t_coords coord1, int color)
{
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		e2;

	x0 = coord0.x;
	y0 = coord0.y;
	dx = abs(coord1.x - coord0.x);
	dy = -abs(coord1.y - coord0.y);
	sx = coord0.x < coord1.x ? 1 : -1;
	sy = coord0.y < coord1.y ? 1 : -1;
	error = dx + dy;
	while (1)
	{
		plot_pixel(fdf, x0, y0, color);
		if ((x0 == coord1.x || x0 < 0) && (y0 == coord1.y || y0 < 0))
			break ;
		e2 = error + 1;
		if (e2 >= dy && x0 != coord1.x)
		{
			error += dy;
			x0 += sx;
		}
		if (e2 <= dx && y0 != coord1.y)
		{
			error += dx;
			y0 += sy;
		}
	}
	// plot_pixel(fdf, x0, y0);	
}

void		vis_center(t_fdf *fdf)
{
	t_coords	coord0;
	t_coords	coord1;

	coord0.x = fdf->center.x;
	coord0.y = 0;
	coord1.x = fdf->center.x;
	coord1.y = HEIGHT;
	bresenham_line(fdf, coord0, coord1, 46546);
	coord0.x = 0;
	coord0.y = fdf->center.y;
	coord1.x = WIDTH;
	coord1.y = fdf->center.y;
	bresenham_line(fdf, coord0, coord1, 46546);

}

void		vis_map(t_fdf *fdf)
{
	int	x;
	int	y;
	int color;
	t_coords **coords;

	x = 0;
	y = 0;
	color = 65280;
	coords = fdf->coords;
	ft_printf("height = %i width = %i\n", fdf->height, fdf->width);
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
	vis_center(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}
