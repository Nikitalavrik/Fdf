/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:58:23 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 17:36:21 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	rot_y(t_fdf *fdf, t_coords *coord)
{
	int		x;

	x = coord->x;
	coord->x = fdf->center.x + (x - fdf->center.x) * cos(fdf->left_right) + coord->z * sin(fdf->left_right);
	coord->z = -(x - fdf->center.x) * sin(fdf->left_right) + coord->z * cos(fdf->left_right);
}

void	rot_x(t_fdf *fdf, t_coords *coord)
{
	int y;

	y = coord->y;
	coord->y =  fdf->center.y + (y - fdf->center.y) * cos(fdf->up_down) + coord->z * sin(fdf->up_down);
	coord->z = -(y - fdf->center.y) * sin(fdf->up_down) + coord->z * cos(fdf->up_down);
}

void	zoom_it(t_fdf *fdf, t_coords *coord)
{
	coord->x *= fdf->zoom;
	coord->y *= fdf->zoom;
	coord->z *= fdf->zoom;
}

void	change_view(t_fdf *fdf, t_coords **coords, int key)
{
	int	x;
	int	y;

	ft_printf("center %i %i\n", fdf->center.x, fdf->center.y);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (key == 125 || key == 126)
				rot_x(fdf, &coords[y][x]);
			if (key == 123 || key == 124)
				rot_y(fdf, &coords[y][x]);
			if (key == 69 || key == 78)
				zoom_it(fdf, &coords[y][x]);
			x++;
		}
		y++;
	}
}
