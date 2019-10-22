/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:16:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/22 20:13:55 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

// int			abs(int	num)
// {
// 	return (num > 0 ? num : -num)
// }

void		plot_pixel(t_fdf *fdf, int x, int y)
{
	int pos;

	pos = 0;
	if (x >= 0 && y >= 0)
	{
		pos = x + y * WIDTH;
		fdf->addr[pos] = 65280;
	}
		
}

void		bresenham_line(t_fdf *fdf, t_coords coord0, t_coords coord1)
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
		plot_pixel(fdf, x0, y0);
		if (x0 < 0)
		{
			ft_printf("dx = %i dy = %i\n", dx, dy);
			ft_printf("x0 = %i y0 = %i x1 = %i y1 %i\n",
			coord0.x, coord0.y, coord1.x, coord1.y);
			exit(1);
		}
		if (x0 == coord1.x && y0 == coord1.y)
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

void		vis_map(t_fdf *fdf, t_coords **coords)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	ft_printf("height = %i width = %i\n", fdf->height, fdf->width);
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x != fdf->width - 1)
				bresenham_line(fdf, coords[y][x], coords[y][x + 1]);
			if (y != fdf->height - 1)
				bresenham_line(fdf, coords[y][x], coords[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}
