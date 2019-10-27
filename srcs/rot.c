/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:58:23 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/27 15:50:07 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	rot_y(t_fdf *fdf, t_coords *coord)
{
	int		x;

	x = coord->x;
	coord->x = fdf->center.x + (x - fdf->center.x) * cos(fdf->left_right)\
											+ coord->z * sin(fdf->left_right);
	coord->z = -(x - fdf->center.x) * sin(fdf->left_right)\
											+ coord->z * cos(fdf->left_right);
}

void	rot_x(t_fdf *fdf, t_coords *coord)
{
	int y;

	y = coord->y;
	coord->y = fdf->center.y + (y - fdf->center.y) * cos(fdf->up_down)\
											+ coord->z * sin(fdf->up_down);
	coord->z = -(y - fdf->center.y) * sin(fdf->up_down)\
											+ coord->z * cos(fdf->up_down);
}

void	change_view(t_fdf *fdf, t_coords **coords)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			rot_x(fdf, &coords[y][x]);
			rot_y(fdf, &coords[y][x]);
			x++;
		}
		y++;
	}
}

void	string_toolbar(t_fdf *fdf)
{
	int c;
	int	width;

	c = 0x2795a3;
	width = WIDTH - 180;
	mlx_string_put(fdf->mlx, fdf->win, width + 60, 10, c, "MENU");
	mlx_string_put(fdf->mlx, fdf->win, width, 50, c, "ESC - exit");
	mlx_string_put(fdf->mlx, fdf->win, width, 70, c, "^  - rotate up");
	mlx_string_put(fdf->mlx, fdf->win, width, 90, c, "  - rotate down");
	mlx_string_put(fdf->mlx, fdf->win, width, 110, c, "<- - rotate left");
	mlx_string_put(fdf->mlx, fdf->win, width, 130, c, "-> - rotate right");
	mlx_string_put(fdf->mlx, fdf->win, width, 150, c, "I  - iso");
	mlx_string_put(fdf->mlx, fdf->win, width, 170, c, "C  - canonic");
}
