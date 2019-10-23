/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:07:48 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/23 15:58:24 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

t_coords	**rerange_coords(t_fdf *fdf, t_coords **coords, t_coords sizes)
{
	int	y;
	int	x;
	int	step_x;
	int	step_y;
	int	padding_x;
	int	padding_y;

	y = 0;
	step_x = (WIDTH - 100) / sizes.x;
	step_y = (HEIGHT - 100) / sizes.y;
	step_x = 100;
	padding_x = (WIDTH - fdf->width * step_y) / 2;
	padding_y = (HEIGHT - fdf->height * step_y) / 2;
	while (y < sizes.y)
	{
		x = 0;
		while (x < sizes.x)
		{
			coords[y][x].x = coords[y][x].x * step_y + padding_x;
			coords[y][x].y = coords[y][x].y * step_y + padding_y;
			coords[y][x].z *= step_y;
			x++;
		}
		y++;
	}
	return (coords);
}

t_fdf	*setup_fdf(t_coords sizes, t_coords **coords)
{
	t_fdf *fdf;

	fdf = ft_memalloc(sizeof(t_fdf));
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->addr = (int *)mlx_get_data_addr(fdf->image, &fdf->bits_per_pixel,
											&fdf->size_line, &fdf->endian);
	fdf->height = sizes.y;
	fdf->width = sizes.x;
	fdf->center.y = HEIGHT / 2;
	fdf->center.x = WIDTH / 2;
	fdf->up_down = 0.0f;
	fdf->left_right = 0.0f;
	fdf->coords = coords;
	return (fdf);
}
